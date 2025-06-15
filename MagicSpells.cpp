#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    Fireball* fire_ptr = dynamic_cast<Fireball*>(spell);
    Frostbite* frost_ptr = dynamic_cast<Frostbite*>(spell);
    Waterbolt* water_ptr = dynamic_cast<Waterbolt*>(spell);
    Thunderstorm* thunder_ptr = dynamic_cast<Thunderstorm*>(spell);

    if(fire_ptr) {
        fire_ptr->revealFirepower();
    } else if(frost_ptr) {
        frost_ptr->revealFrostpower();
    } else if(water_ptr) {
        water_ptr->revealWaterpower();
    } else if(thunder_ptr) {
        thunder_ptr->revealThunderpower();
    } else {
        auto s1 = spell->revealScrollName();
        auto s2 = SpellJournal::journal;
                
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        
        for(int i = s1.size() - 1; i > -1; --i){
            for(int j = s2.size() - 1; j > -1; --j){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        
        cout << dp[0][0] << endl;
    }

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}