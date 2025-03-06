/**
 * @brief class/function to send a trade order 
 * 
 */

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>


namespace MyOrderBook
{
    using namespace std;

    using best_bid = pair<int, int>;

    enum class OrderType
    {
        Buy,
        Sell,
    };
    
    struct TradeOrder
    {
        string security_id;
        uint32_t quantity;
        uint32_t order_id;
        double price;
        OrderType order;
    };
    
    class OrderBook
    {
    public:
        OrderBook(const std::string& symbol)
        : m_symbol(symbol)
        {}

        void add_order(TradeOrder& order)
        {
            auto new_order = make_shared<TradeOrder>(order);
            if(new_order->order == OrderType::Sell)
            {
                m_sell_order_book[new_order->price].push_back(new_order);
            }
            else if(new_order->order == OrderType::Buy)
            {
                m_buy_order_book[new_order->price].push_back(new_order);
            }
        }

        void match_orders()
        {
            auto sell_itr = m_sell_order_book.begin();
            auto buy_itr = m_buy_order_book.begin();
            while(sell_itr->first <= buy_itr->first)
            {
                auto& buy_queue = buy_itr->second;
                auto& sell_queue = sell_itr->second;

                auto matched_qty = min(buy_queue.front()->quantity, sell_queue.front()->quantity);

                buy_queue.front()->quantity -= matched_qty;
                sell_queue.front()->quantity -= matched_qty;

                if(buy_queue.front()->quantity == 0)
                {
                    auto matched_order = buy_queue.front();
                    buy_queue.pop_front();

                    m_completed_orders.push_back(matched_order);
                }

                if(sell_queue.front()->quantity == 0)
                {
                    auto matched_order = sell_queue.front();
                    sell_queue.pop_front();

                    m_completed_orders.push_back(matched_order);
                }

                if(buy_queue.empty()) ++buy_itr;
                
                if(sell_queue.empty()) ++sell_itr;
            }

            if(buy_itr != m_buy_order_book.begin()) m_buy_order_book.erase(m_buy_order_book.begin(), buy_itr);

            if(sell_itr != m_sell_order_book.begin()) m_sell_order_book.erase(m_sell_order_book.begin(), sell_itr);          
        }

        void update_order_book();

        best_bid get_best_bid_offer();

        void print_order_book();

    private:
        string m_symbol {};
        map<double, list<shared_ptr<TradeOrder>>, greater<double>> m_buy_order_book;
        map<double, list<shared_ptr<TradeOrder>>> m_sell_order_book;
        vector<shared_ptr<TradeOrder>> m_completed_orders;
    };

    class OrderManager
    {
        public:
            shared_ptr<OrderBook> get_order_book(const string& symbol)
            {
                if(m_order_manager.count(symbol))
                {
                    return m_order_manager[symbol];
                }
                else
                {
                    return m_order_manager[symbol] = make_shared<OrderBook>(symbol);
                }
            }

            void send_order(TradeOrder& order)
            {
                if(order.price < 0 || order.quantity <= 0)
                {
                    throw invalid_argument("Invalid order entered! Order has been discarded");
                }

                auto order_book = get_order_book(order.security_id);

                order_book->add_order(order);
            }


        private:
            unordered_map<string, shared_ptr<OrderBook>> m_order_manager;
    };
    
};


int main()
{
    using namespace MyOrderBook;

    try
    {
        auto manager = make_unique<OrderManager>();

        if(manager)
        {
            TradeOrder first_order {"APPL", 10, 1, 2.5, OrderType::Buy};
            manager->send_order(first_order);
        }
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}