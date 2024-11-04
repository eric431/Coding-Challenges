use std::io::{self, BufRead}

mod matching_engine
{
    // enum to represent the order types for the order struct
    enum OrderType {
        Buy,
        Sell,
    }

    struct Order{
        id: usize, // might have to be changed to an appropriate type
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

    // extract order book data from stdin
    fn read_input(input: &mut String)
    {
        println!("{}", input);
    }

    // parse input into order book
    fn parse_data(input: &mut String, sell_order_map: &mut HashMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>)
    {
        let iter = input.split_whitespace();
        let fields:Vec<&str> = iter.collect();
        
        let mut s = String::new();
        let mut parsed_order_vec = Vec::new();
        for f in fields.iter(){
            s = f.to_string();
            if (&s != "@") && (&s != "BTC") && (&s != "USD")
            {
                s.retain(|c| {![':'].contains(&c)});
                parsed_order_vec.push(s.clone());
            }
        }
    
        if parsed_order_vec.len() == 4
        {
            let order = Order {
                id: parsed_order_vec[0].parse().expect("Failed to parse string to usize"),
                order_type: match parsed_order_vec[1].as_str() {
                    "Buy" => OrderType::Buy,
                    "Sell" => OrderType::Sell,
                    _ => panic!("Invalid type entered!"),
                },
                quantity: parsed_order_vec[2].parse().expect("Failed to parse string to OrderType"),
                price: parsed_order_vec[3].parse().expect("Failed to parse string to OrderType"),
            };
            
            if order.order_type == OrderType::Buy
            {
                buy_order_queue.push_back(order);
            }
            else if order.order_type == OrderType::Sell
            {
                if sell_order_map.contains_key(&order.price)
                {
                    if let Some(x) = sell_order_map.get_mut(&order.price)
                    {
                        x.push_back(order);
                    }                
                }
                else 
                {
                    let mut sell_queue: VecDeque<Order> = VecDeque::new();
                    sell_queue.push_back(order);
                    sell_order_map.insert(order.price, sell_queue);                
                }
            }
        }
    }
    

    // find the sell order with the lowest price 
    fn find_sell_order(sell_order_map: &mut HashMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>)
    {

    }

    // match the appropriate orders
    fn match_orders()
    {
        
    }

    // update order book
    fn update_order_book()
    {

    }

    // format results and print to terminal
    fn print_matched_orders()
    {
        println();
    }


    fn MatchOrders()
    {
        read_input();

        find_sell_order();

        update_order_book();

        print_matched_orders();
    }
}


fn main()
{
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    
    let mut line = String::new();
    handle.read_line(&mut line);
    read_data(&mut line);
    
    // for line in handle.lines()
    // {
    //     // read_data(line);
    //     println!("{}", line.unwrap());
    // }
}





use std::io::{self, BufRead};
use std::collections::HashMap;
use std::collections::VecDeque;
// use std::sync::LazyLock;
// use std::any::type_name;

// fn type_of<T>(_: T) -> &'static str {
//     type_name::<T>()
// }

// // enum to represent the order types for the order struct
#[derive(Debug, PartialEq, Eq, Copy, Clone)]
enum OrderType {
    Buy,
    Sell,
}

#[derive(Debug, PartialEq, Eq, Copy, Clone)]
struct Order{
    id: usize, // might have to be changed to an appropriate type
    order_type: OrderType,
    price: u32,
    quantity: u32
}

// struct Trade {
//     buy_id: usize,
//     sell_id: usize,
//     price: u32,
//     quantity_traded: u32
// }

fn read_data(input: &mut String)
{
    println!("{}", input);
}

fn parse_data(input: &mut String, sell_order_map: &mut HashMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>)
{
    let iter = input.split_whitespace();
    let fields:Vec<&str> = iter.collect();
    
    let mut s = String::new();
    let mut parsed_order_vec = Vec::new();
    for f in fields.iter(){
        s = f.to_string();
        if (&s != "@") && (&s != "BTC") && (&s != "USD")
        {
            s.retain(|c| {![':'].contains(&c)});
            parsed_order_vec.push(s.clone());
        }
    }

    if parsed_order_vec.len() == 4
    {
        let order = Order {
            id: parsed_order_vec[0].parse().expect("Failed to parse string to usize"),
            order_type: match parsed_order_vec[1].as_str() {
                "Buy" => OrderType::Buy,
                "Sell" => OrderType::Sell,
                _ => panic!("Invalid type entered!"),
            },
            quantity: parsed_order_vec[2].parse().expect("Failed to parse string to OrderType"),
            price: parsed_order_vec[3].parse().expect("Failed to parse string to OrderType"),
        };
        
        if order.order_type == OrderType::Buy
        {
            buy_order_queue.push_back(order);
        }
        else if order.order_type == OrderType::Sell
        {
            if sell_order_map.contains_key(&order.price)
            {
                if let Some(x) = sell_order_map.get_mut(&order.price)
                {
                    x.push_back(order);
                }                
            }
            else 
            {
                let mut sell_queue: VecDeque<Order> = VecDeque::new();
                sell_queue.push_back(order);
                sell_order_map.insert(order.price, sell_queue);                
            }
        }
    }
}

// find the sell order with the lowest price 
fn find_sell_order(sell_order_map: &mut HashMap<u32, VecDeque<Order>>, buy_order_queue: &mut VecDeque<Order>)
{
    while sell_order_map.len() > 0 && buy_order_queue.len() > 0
    {
        println!("Matching orders...");
    }
}

fn main() {

    // let mut sell_order_map: HashMap<u32, VecDeque<Order>> = HashMap::new();    
    // let mut buy_order_queue: VecDeque<Order> = VecDeque::new();

    // let stdin = io::stdin();
    // let mut handle = stdin.lock();
    
    // let mut line = String::new();
    // handle.read_line(&mut line);
    // read_data(&mut line);
    // parse_data(&mut line, &mut sell_order_map, &mut buy_order_queue);
    
    // for line in handle.lines()
    // {
    //     // read_data(line.unwrap());
    //     println!("{}", line.unwrap());
    // }
    
    println!("{Hello}");
}
