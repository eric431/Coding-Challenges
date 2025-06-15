class Solution {
    public:
        int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
            int x = location[0], y = location[1];
            static constexpr double conv_factor = 180.0 / M_PI;
    
            int visible {0};
            vector<double> angles;
            for(auto &point : points){
                if(point == location){
                    ++visible;
                    continue;
                }
    
                double angle = atan2(point[1] - y, point[0] - x) * conv_factor;
                angle += 360 * (angle < 0);
                angles.push_back(angle);
            }
            sort(angles.begin(), angles.end());
    
            int p1 = 0, p2 = 0;
            int n = angles.size();
            int max_points {visible};
            while(p1 < angles.size()){
                if(max_points == points.size()) break;
    
                if(p2 < angles.size() && angles[p1] + angle < 360 && angles[p2] <= (angles[p1] + angle)){                
                    max_points = max(max_points, visible + p2 - p1 + 1);
                    ++p2;
                } else if(angles[p1] + angle >= 360 && (p2 >= n && angles[p2 % n] <= (angles[p1] + angle) - 360 || p2 < n && angles[p2] <= (angles[p1] + angle)) ){
                    int p3 = (p2 >= n) * (n + p2 % n) + (p2 < n) * p2;
                    max_points = max(max_points, visible + p3 - p1 + 1);
                    ++p2;
                } else {
                    ++p1;
                }
            }
    
            return max_points;
        }
    };