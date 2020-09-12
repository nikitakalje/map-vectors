
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

class Restaurant {
private:
  unordered_map<string, double> sales;

public:
  Restaurant() { };

  // Read the given text file. Each line in the input file
  // is a food name and amount of the sale (including $ sign).
  // Food name and amount are separated by space.
  // Read the input file and keep one entry per food item in the member
  // variable sales. The key is the food name, and the value is to total
  // value of sales.
  void ReadFile(string fname) {

    ifstream fin;
    fin.open(fname);

    string line;
    string name;
    double val;
    while(getline(fin, line))
    {

      int nameIdx=line.find(' ');
      name=line.substr(0, nameIdx);

      val=stod(line.substr(nameIdx+2));

      unordered_map<string, double>::iterator it;


      for(it = sales.begin(); it!=sales.end(); it++)
      {
        if(it->first ==name)
        {
          it->second+=val;
        }
      }
      sales.insert(pair<string, double>(name,val));
    }


    fin.close();


  };


  // Print the total sales by name of the food item, in alphabetical order.
  // First print "Total by name".
  // Then for each food item, print one line. The line contains the food name,
  // space, and then the total value of sales.
  void PrintByName() {

    cout<<"Total by name: "<<endl;
    //vector<Restaurant> rest_vec;
    //vector<string> rest_vec;
    vector<pair<string, double> >rest_vec;


    //copy(sales.begin(), sales.end(), rest_vec.begin());
    rest_vec.reserve(sales.size());

    for(auto const& pair: sales)
    {
      rest_vec.push_back(make_pair(pair.first, pair.second));
    }

    sort(rest_vec.begin(), rest_vec.end());

    for(int i=0; i<rest_vec.size(); i++)
    {
      cout<<rest_vec[i].first<<" $"<<rest_vec[i].second<<endl;
    }



  };

  // Print the total sales in order of total sales amount.
  // First print "Total by amount".
  // Then for each food item, print one line. The line contains the food name,
  // space, and then the total value of sales.
  void PrintByAmount() {

    cout<<"Total by value: "<<endl;
    //vector<Restaurant> rest_vec;
    //vector<string> rest_vec;
    vector<pair<double, string> >rest_vec;


    //copy(sales.begin(), sales.end(), rest_vec.begin());
    rest_vec.reserve(sales.size());

    for(auto const& pair: sales)
    {
      rest_vec.push_back(make_pair(pair.second, pair.first));
    }

    sort(rest_vec.begin(), rest_vec.end());

    //for(int i=0; i<rest_vec.size(); i++)
    for(int i=rest_vec.size()-1; i>=0; i--)
    {
      cout<<rest_vec[i].second<<" $"<<rest_vec[i].first<<endl;
    }

  };
};

int main() {
  Restaurant R;
    cout<<"Using vectors: "<<endl<<endl;
  R.ReadFile("input.txt");

  R.PrintByName();


  cout << endl;
  R.PrintByAmount();
  return 0;
}
