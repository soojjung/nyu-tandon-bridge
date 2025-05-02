#include <iostream>
using namespace std;

int main() {
  double price1, price2, taxRate;
  char clubCard;

  cout << "Enter price of first item: ";
  cin >> price1;
  cout << "Enter price of second item: ";
  cin >> price2;
  cout << "Does customer have a club card? (Y/N): ";
  cin >> clubCard;
  cout << "Enter tax rate, e.g 5.5 for 5.5% tax: ";
  cin >> taxRate;

  double basePrice = (price1 + price2) / 1.0;

  double minPrice, maxPrice;
  if (price1 > price2) {
    maxPrice = price1;
    minPrice = price2;
  } else {
    maxPrice = price2;
    minPrice = price1;
  }

  double discountPrice = maxPrice + (minPrice * 0.5);

  if (clubCard == 'Y' || clubCard == 'y') {
    discountPrice *= 0.9;
  }

  double totalPrice = discountPrice * (1 + taxRate / 100);

  cout << "Base price: " << basePrice << endl;
  cout << "Price after discounts: " << discountPrice << endl;
  cout << "Total price: " << totalPrice << endl;

  return 0;
}
