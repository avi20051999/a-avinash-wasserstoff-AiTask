#include<string>

#include<vector>

#include<map>

#include<iostream>

#include<fstream>

using namespace std;
using std::ifstream;
struct Date {
  int days, month, year;
};
vector < string > processing(string file) {

  ifstream indata;
  indata.open(file);
  int numberOfOrders = 0;

  indata >> numberOfOrders;
  vector < string > result;
  map < string, int > productFrequency;
  string productName;
  int productCount;
  Date orderedAgo;
  string maximumOrderedProduct = "", secondMaximumOrderedProduct = "";
  for (int orderId = 0; orderId < numberOfOrders; ++orderId) {
    int numberOfProducts = 0;
    indata >> numberOfProducts;
    indata >> orderedAgo.days;
    indata >> orderedAgo.month;
    indata >> orderedAgo.year;
    for (int productId = 0; productId < numberOfProducts; ++productId) {
      indata >> productName;
      indata >> productCount;

      if (orderedAgo.days <= 30 && orderedAgo.month == 0 && orderedAgo.year == 0) {
        productFrequency[productName] = productCount;

        if (maximumOrderedProduct == "") {
          maximumOrderedProduct = productName;
        } else if (secondMaximumOrderedProduct == "") {
          if (productFrequency[productName] > productFrequency[maximumOrderedProduct]) {
            secondMaximumOrderedProduct = maximumOrderedProduct;
            maximumOrderedProduct = productName;
          } else {
            secondMaximumOrderedProduct = productName;
          }
        } else {
          if (productFrequency[maximumOrderedProduct] < productFrequency[productName]) {
            secondMaximumOrderedProduct = maximumOrderedProduct;
            maximumOrderedProduct = productName;
          } else if (productFrequency[secondMaximumOrderedProduct] < productFrequency[productName]) {
            secondMaximumOrderedProduct = productName;
          }
        }
      }
    }
  }

  if (maximumOrderedProduct == "") {
    return result;
  }
  result.push_back(maximumOrderedProduct);
  if (secondMaximumOrderedProduct == "") {
    return result;
  }
  result.push_back(secondMaximumOrderedProduct);
  return result;

}

int main() {
  vector < string > output = processing("example.txt");
  assert(output.size() == 2);
  assert(output[0] == "Mobile");
  assert(output[1] == "Book");
}
