use std::io::{self, BufRead};
use std::collections::BTreeMap;
use std::collections::VecDeque;
use std::cmp;

// // enum to represent the order types for the order struct
#[derive(PartialEq, Eq, Copy, Clone)]
enum OrderType {
    Buy,
    Sell,
}

#[derive(PartialEq, Eq, Copy, Clone)]
struct Order{
    id: usize,
    order_type: OrderType,
    price: u32,
    quantity: u32
}

struct Trade {
    buy_id: usize,
    sell_id: usize,
    price: u32,
    quantity_traded: u32
}

fn validate_quantity_and_price(order_quantity: u32, order_price: u32, order_id: usize) -> bool
{
    if order_quantity < 1 // minimum valid order quantity
    {
        println!("Order {order_id} size is invalid! This order message has been discarded.");
        return false;
    }
    else if order_quantity > 999 // maximum valid order quantity
    {
        println!("Order {order_id} size is too large! This order message has been discarded.");
        return false;
    }

    if order_price < 1 // minimum valid order price
    {
        println!("Order {order_id} price is invalid! This Order message has been discarded.");
        return false;
    }
    else if order_price > 99999 // maximum valid order price
    {
        println!("Order {order_id} price is too large! This order message has been discarded.");
        return false;
    }
    
    return true;
}

fn parse_data(input: &mut String, order_book: &mut BTreeMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>)
{
    let iter = input.split_whitespace();
    let fields:Vec<&str> = iter.collect();
    
    let mut parsed_order_vec = Vec::new();
    for f in fields.iter(){
        let mut s = f.to_string();
        if (&s != "@") && (&s != "BTC") && (&s != "USD")
        {
            s.retain(|c| {![':'].contains(&c)});
            parsed_order_vec.push(s.clone());
        }
    }

    if parsed_order_vec.len() == 4
    {
        let order = Order {
            id: match parsed_order_vec[0].parse() 
            {
                Ok(id) => id,
                Err(_) => { println!("Error encountered parsing order id! Order message has been discarded.");
                            return;
                            }
            },
            order_type: match parsed_order_vec[1].as_str() {
                "Buy" => OrderType::Buy,
                "Sell" => OrderType::Sell,
                _ => panic!("Invalid type entered!")
            },
            quantity: match parsed_order_vec[2].parse()
            {
                Ok(quantity) => quantity,
                Err(_) => { println!("Error encountered parsing order quantity! Order message has been discarded.");
                            return;
                            }
            },
            price: match parsed_order_vec[3].parse()
            {
                Ok(price) => price,
                Err(_) => { println!("Error encountered parsing order price! Order message has been discarded.");
                            return;
                            }                
            }
        };
        
        if !validate_quantity_and_price(order.quantity, order.price, order.id)
        {
            return;
        }
        
        if order.order_type == OrderType::Buy
        {
            buy_order_queue.push_back(order);
        }
        else if order.order_type == OrderType::Sell
        {
            if order_book.contains_key(&order.price)
            {
                if let Some(sell_order) = order_book.get_mut(&order.price)
                {
                    sell_order.push_back(order);
                }                
            }
            else 
            {
                let mut sell_queue: VecDeque<Order> = VecDeque::new();
                sell_queue.push_back(order);
                order_book.insert(order.price, sell_queue);                
            }
        }
    }
}

// format results and print to terminal
fn print_matched_orders(trade: &mut Trade)
{
    println!("Trade {0} BTC @ {1} USD between {2} and {3}", trade.quantity_traded, trade.price, trade.buy_id, trade.sell_id);
}

// update order book
fn update_order_book(order_book: &mut BTreeMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>, trade_price: u32)
{
    let buy_order = buy_order_queue.front_mut().unwrap();
    if let Some(sell_order) = order_book.get_mut(&trade_price)
    {
        let sell_q = sell_order.front().unwrap().quantity;
        let buy_q = buy_order.quantity;
        
        sell_order.front_mut().unwrap().quantity = sell_q - cmp::min(buy_q, sell_q);
        buy_order.quantity = buy_q - cmp::min(buy_q, sell_q);
        
        if sell_order.front().unwrap().quantity == 0
        {
            sell_order.pop_front();
            if sell_order.len() == 0
            {
                order_book.remove(&trade_price);
            }
        }
        if (buy_order.quantity == 0) || (order_book.len() == 0)
        {
            buy_order_queue.pop_front();
            if (order_book.len() == 0) && (buy_order_queue.len() > 0)
            {
                buy_order_queue.clear();
            }
        }
    }
}

// find the sell order with the lowest price 
fn match_buy_order_to_sell_order(order_book: &mut BTreeMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>)
{
    let mut update_flag: bool = false;
    let mut trade = Trade{
        buy_id: 0, sell_id: 0, price: 0, quantity_traded: 0
    };
    
    while order_book.len() > 0 && buy_order_queue.len() > 0
    {
        for (sell_order_price, sell_order_queue) in order_book.iter()
        {
            let buy_order = buy_order_queue.front().unwrap();
            if buy_order.price >= *sell_order_price
            {
                let sell_q = sell_order_queue.front().unwrap().quantity;
                let buy_q = buy_order.quantity;
                trade.quantity_traded = cmp::min(buy_q, sell_q);

                trade.price = *sell_order_price;

                trade.buy_id = buy_order.id;
                trade.sell_id = sell_order_queue.front().unwrap().id;
                
                update_flag = true;
                break;
            }
        }
        
        if update_flag == true
        {
            print_matched_orders(&mut trade);
            update_order_book(order_book, buy_order_queue, trade.price);
            update_flag = false;
        }
    }
}

// match the incoming orders
fn match_orders(input: &mut String, order_book: &mut BTreeMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>)
{
    parse_data(input,  order_book, buy_order_queue);
    
    if (order_book.len() > 0) && (buy_order_queue.len() > 0)
    {
        match_buy_order_to_sell_order(order_book, buy_order_queue);
    }
    else if(order_book.len() == 0) && (buy_order_queue.len() > 0)
    {
        // if order book is empty discard whatever buy orders are left
        buy_order_queue.clear();
    }
}

fn main() {

    let mut order_book: BTreeMap<u32, VecDeque<Order>> = BTreeMap::new();    
    let mut buy_order_queue: VecDeque<Order> = VecDeque::new();

    let stdin = io::stdin();
    for line in stdin.lock().lines()
    {
        match_orders(&mut line.unwrap(), &mut order_book, &mut buy_order_queue);
    }
}
