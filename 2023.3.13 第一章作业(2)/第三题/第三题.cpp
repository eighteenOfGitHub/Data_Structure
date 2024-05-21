#include"List.hpp"
List<int> subset;
List<List<int>> subset_house;

template<class T>
bool repeat()
{
	if (subset_house.get_head()->next == NULL)
		return false;
	Node<List<T>>* newlist=subset_house.get_head()->next;
	while (newlist!=NULL)
	{
		if (newlist->data != subset)
			return true;
		newlist = newlist->next;
	}
	return false;
}

void showson()
{
	cout << "{";
	subset.show();
	cout << "}" << endl;
}

template<class T>
void getson1(int m, int max)
{
	subset.append(m);
	showson();
	if (!repeat<int>())
	{
		if (m < max)
		{
			List<T> newlist(subset);		//���
			subset_house.append(newlist);

			m++;
			getson1<int>(m, max);
		}
		else
		{
			List<T> newlist(subset);		//���
			subset_house.append(newlist);
			subset.delete_end();
			if (m > max)
				return;
			m = subset.get_rear_element();
			getson2<int>(m, max);
		}
	}
}

template<class T>
void getson2(int m, int max)
{
	if(repeat<int>())
	{
		if (m < max)
		{
			subset.delete_end();
			m++;
			getson1<int>(m, max);
		}
	}
}


int main()
{
	cout << "������Ԫ������n(0<n<100):";
	int n;
	cin >> n;
	cout << "�ü��ϵ��ݼ�Ϊ��" << endl;
	getson1<int>(1, n);

	cout << "�Ӽ�����Ϊ��" << subset_house.length() + 1 << endl;


	return 0;
}