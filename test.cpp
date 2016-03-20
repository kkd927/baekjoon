#include <iostream>
#include <list>
#include <functional>

using namespace std;

// 아이템 구조체
struct Item
{
	Item(int itemCd, int buyMoney)
	{
		ItemCd = itemCd;
		BuyMoney = buyMoney;
	}

	int ItemCd;  // 아이템 코드
	int BuyMoney;  // 판매 금액
};

template <typename T> struct COMPARE_ITEM 
{
	bool operator() (const T l, const T r) const
	{
		return l.ItemCd < r.ItemCd;
	}
};

void main()
{
	list< int > list1;

	list1.push_back(20);
	list1.push_back(10);
	list1.push_back(30);
	list1.push_back(15);
	list1.push_back(12);

	cout << "sort 올림차순" << endl;
	list1.sort();

	for (list< int >::iterator iterPos = list1.begin(); iterPos != list1.end(); iterPos++)
	{
		cout << "list 1: " << *iterPos << endl;
	}

	cout << "sort 내림차순" << endl;
	list1.sort( greater< int >());

	for (list< int >::iterator iterPos = list1.begin(); iterPos != list1.end(); iterPos++)
	{
		cout << "list 1: " << *iterPos << endl;
	}

	cout << endl << "sort - 유저가 정의한 방식으로 정렬" << endl;
	list< Item > Itemlist;

	Item item1(20, 200);
	Item item2(10, 100);
	Item item3(50, 300);

	Itemlist.push_back(item1);
	Itemlist.push_back(item2);
	Itemlist.push_back(item3);

	Itemlist.sort( COMPARE_ITEM< Item >() );

	for (list< Item >::iterator iterPos = Itemlist.begin(); iterPos != Itemlist.end(); iterPos++)
		cout << "Itemlist : " << iterPos->ItemCd << endl;
}