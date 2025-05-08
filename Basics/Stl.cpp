#include <bits/stdc++.h>
using namespace std;


void explainPair(){
	pair<int,int> p ={1,3};
	cout<<p.first<<" "<<p.second<<endl;
	
	//Nested Pair
	pair <int,pair<int,int>> np = {1,{3,4}};
	cout<<np.first<<" "<<np.second.second<<" "<<np.second.first<<endl;
	
	//Array of pair
	pair<int,int> arr[]={{1,2},{3,4},{5,6}};
	cout<<arr[1].second;
	
	
}
	
//Vector- dynamic in nature no fixed size

void explainVector(){
	
	vector<int> v;
	
	v.push_back(1); //emplace is faster than push
	v.emplace_back(2);
	
	vector<pair<int,int>>vec;
	
	vec.push_back({1,2}); //needs to put like pair
	vec.emplace_back(1,2); //automatically assumes them to be pair
	
	vector<int> nvec(5,100); //vector with 5 instances/size of 100
	
	vector<int> vp(5);//vector of 5 size of 0 or any garbage value , size can be increased
	
	vector<int>v1(5,20);
	vector<int>v2(v1); //copies v1 into v2
	
	//Iterators - that help to manipulate data in container
	
	vector<int>::iterator it = v.begin(); //points to the memory address
	it++;
	cout<<*(it)<endl; //prints value stored on that particular memory address
	
	
	it = it+2;
	
	vector<int>::iterator it =v.end(); // end points to memory location right after last one
	vector<int>::iterator it =v.rend(); // one before the first value
	vector<int>::iterator it =v.rbegin(); //last element , moves in reverse fashion if i do ++ it will go one step back 
	
	cout<<v.at(0);
	cout<<v.back()<<" "; //gives the last element
	
	for(vector<int> iterator it =v.begin(); it !=v.end();it++){
		cout<<*(it)<<" ";
	}
	
	for(auto it =v.begin(); it !=v.end();it++){ //automatically defines the data type // auto a=5;
		cout<<*(it)<<" ";
	}
	
	//deletion in vector
	
	v.erase(v.begin()+1); // second elem gets deleted
	v.erase(v.begin()+2,v.begin()+4) // 2 and 3rd elem get deleted
	
	//insertion
	
	vector<int> v(2,100); //(100,100)
	v.insert(v.begin(),300); // {300,100,100}
	v.insert(v.begin()+1,2,10); //(300,10,10,100,100)
	
	vector<int>copy(2,50); //{50,50}
	v.insert(v.begin(),copy.begin.copy.end())//{50,50,300,10,10,100,100}
	
	cout<<v.size(); //2
	
	//{10,20}
	v.pop_back();	//{10} 
	
	//v1 -> {10,20}
	//v2 -> {30,40}
	v1.swap(v2) //v1={30,40} //v2={10,20}
	
	v.clear(); //erases the entire vectorv-> {}
	
	cout<<v.empty(); //true or false
}

void explainList(){ //provides front operations as well
	
	list<int> ls;
	
	ls.push_back(2); //{2}
	ls.emplace_back(4); //{2,4}
	ls.push_front(5); //{5,2,4} cheap rather than insert in vector
	ls.emplace_front(); //
	 
}

void explainDeque(){
	deque<int>dq;
	
	dq.push_back(1); //{1}
	dq.emplace_back(2); //{1,2}
	dq.push_front(4); //{4,1,2}
	dq.emplace_front(3); //{3,4,1,2}
	
	dq.pop_back(); //{3,4,1};
	dq.pop_front(); //{4,1}
	
	dq.back();
	dq.front();
}
void explainStack(){ //Last In First Out // indexing access is not allowed //push,pop,top
	
	stack<int>st;
	st.push(1); //{1}
	st.push(2); //{2,1}
	st.push(3);	//{3,2,1}
	st.push(3);	//{3,3,2,1}
	
	st.emplace(5); //{5,3,3,2,1}
	
	cout<<st.top(); //prints 5 // st[2] is invalid
	
	st.pop(); //{3,3,2,1}
	
	cout<<st.top(); //3
	
	cout<<st.size(); //4
	
	cout<<st.empty();
	
	stack <int> st1,st2;
	st1.swap(st2);
	
	
}

void explainQueue(){ //First In First Out
	queue<int>q;
	q.push(1); //{1}
	q.push(2); //{1,2}
	q.emplace(4); //{1,2,4}
	
	q.back()+=5 
	
	cout<<q.back(); //prints 9
	
	q.front(); //1
	
	q.pop(); //{2,9}
	
	//size swap same as stack
	
	
}

void priorityQueue(){ //largest elem , number , character stays at the top
	//data is not stored in linear fashion->tree like strutcture
	priority_queue<int> pq;
	
	pq.push(5); //{5}
	pq.push(2); //{5,2}
	pq.push(8); //{8,5,2}
	pq.emplace(10); // {10,8,5,2}
	
	pq.top(); //prints 10
	
	pq.pop(); //{8,5,2}
	
	//Minimum Heap
	priority_queue<int,vector<int>,greater<int>> pq;
	
	pq.push(5); //{5}
	pq.push(2); // {2,5}
	pq.push(8); //{2,5,8}
	pq.emplace(20); //{2,5,8,10}	
	
	pq.top(); //prints 2
	
}

void explainSet(){ //stores everything in sorted order and unique entries
	
	set<int> st;
	st.insert(1); //{1}
	st.emplace(2); //{1,2}
	st.insert(2); //{1,2};
	st.insert(4); //{1,2,4};
	st.insert(3); // {1,2,3,4}
	
	auto it = st.find(3); //returns an iterator that points to 3
	auto it = st.find(6); //if value not present  -> returns an iterator pointing to st.end()
	
	st.erase(5); //erases 5 //takes logarithimic time
	
	int cnt = st.count(1); //if present gives 1 else 0
	
	auto it1 = st.find(2);
	auto st2 = st.find(4);
	st.erase(it1,it2);
	
	//lower_bound and upper_bound function 
	
	auto it = st.lower_bound(2);
	auto it = st.upper_bound(3);
}


void explainMultiSet(){ //sorted but can store multiple occurences
	
	multiset<int>ms;
	ms.insert(1); //{1}
	ms.insert(1); //{1,1}
	ms.insert(1); //{1,1,1}
	
	ms.erase(1); //all 1s are erased
	
	int cnt = ms.count(1);
	
	//only a single one is erased
	ms.erase(ms.find(1));
	
	ms.erase(ms.find(1), ms.find(1)+2);
}

void explainUnorderedSet(){
	unordered_set<int> st; 
	//stores unique elements in non-sorted fashion
	//lower bound and upper bound dont work
	
}

void explainMap() { //like dictionaries , key-value pair 
//,stores unique keys in sorted order
	map<int,int> mp;
	
	map<int,pair<int,int>> mp; //key can be of any data type
	
	mp[1] =2;
	mp.emplace({3,1});
	mp.insert({2,4});
	
	mp[{2,3}]=10;
	
	{
		{1,2},
		{2,4},
		{3,1},
		
	}
	
	for (auto it: mpp){
		cout<< it.first<< " "<<it.second;
	}
	
	auto it = mpp.find(3);
	cout<< *(it).second;
	
	auto it = mpp.find(5); //not present points to mpp.end()

	
}

void explainMultimap(){
	// everything same as maop, only it can store multiple keys
	// only mpp[key] cannot be used here
	//duplicate keys are allowed
}

void explainUnorderedmap(){
	//unique keys but keys will not be sorted
}

bool comp(pair<int,int> p1, pair<int,int> p2 ){ //comparators
		if(p1.second <p2.second) return true;
		if(p1.second>p2.second) return false;
		
		if(p1.first> p2.first) return true;
		return false;
}	

void explainAlgorithms(){
	
	sort(a,a+n)
	sort(v.begin(),v.end())
	
	sort(a+2,a+4); // sorts only 3rd and 4th element
	
	sort(a,a+n,greater<int>) //sorts in descending order
	
	pair<int,int> a[]= {{1,2},{2,1},{4,1}};
	//sort above acc to second element
	//if second element is same, then sort
	//it according to the first elemnt but in descending
	//{{4,1},{2,1},{1,2}}
	
	sort(a,a+n,comp) //->comp - made ourselves
	
	int num=7; //111
	
	int cnt = __builtin_popcount();//-3 //how many 1s are there or how many set bits
	
	long long num = 407028908258938;
	int cnt  = __builtin_popcountll();
	
	string s ="123";
	sort(s.begin(),s.end())
	
	do{
		cout<<s<<endl;
	}while(next_permutation(s.begin(),s.end()))
	
	//prints all permutations like 231 321
	
	int max =  *max_element(a,a+n) //star return the value otherwise you get the address
	
}

// std::lower_bound
//Header: <algorithm>

//Usage: std::lower_bound(start, end, value)

//Returns: Iterator pointing to the first element not less than (i.e., =) value.

//2. std::upper_bound
//Header: <algorithm>

//Usage: std::upper_bound(start, end, value)

//Returns: Iterator pointing to the first element greater than (i.e., >) value.



int main(){
	cout<<"Hishita";
	explainPair();
}

