#include <bits/stdc++.h>
using namespace std;

struct Date
{
    int days, month, year;
};
int main()
{
int numberOfOrders;
cin>>numberOfOrders;
    map<string,int> productFrequency;
string productName;
int productCount;
Date orderedAgo;
string maximumOrderedProduct="", secondMaximumOrderedProduct="";
for(int orderId=0;orderId<numberOfOrders;++orderId)
{
   int numberOfProducts = 0;
   cin>>numberOfProducts;
   cin>>orderedAgo.days;
   cin>>orderedAgo.month;
   cin>>orderedAgo.year;
   for(int productId=0;productId<numberOfProducts;++productId)
   {
       cin>>productName;
       cin>>productCount;
       productFrequency[productName]+=productCount;
       if(orderedAgo.days<=30 && orderedAgo.month==0)
       {
           if(maximumOrderedProduct == "")
           {
               maximumOrderedProduct = productName;
           }
           else if(secondMaximumOrderedProduct == "")
           {
               if(productFrequency[productName] > productFrequency[maximumOrderedProduct])
               {
                   secondMaximumOrderedProduct = maximumOrderedProduct;
                   maximumOrderedProduct = productName;
               }
               else
               {
                   secondMaximumOrderedProduct = productName;
               }
           }
           else
           {
               if(productFrequency[maximumOrderedProduct] < productFrequency[productName])
               {
                        secondMaximumOrderedProduct = maximumOrderedProduct;
                        maximumOrderedProduct = productName;
                    }
                    else if(productFrequency[secondMaximumOrderedProduct] < productFrequency[productName])
                    {
                        secondMaximumOrderedProduct = productName;
                    }
           }
       }
   }
}
if(maximumOrderedProduct=="")
{
   cout<<"There are no products";
}
else
{
cout<<"Maximum ordered product: "<<maximumOrderedProduct<<endl;
}
if(secondMaximumOrderedProduct=="")
{
   cout<<"There is only one product";
}
else
{
cout<<"Second maximum ordered product: "<<secondMaximumOrderedProduct<<endl;
}
return 0;
}