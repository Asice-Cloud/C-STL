// index for rehabilitation
//begining on 6/24

#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include<stdio.h>

/*							                      _ooOoo_
 *							                     o8888888o
 *							                     88" . "88
 *							                     (| -_- |)
 *							                      O\ = /O
 *							                  ____/`---'\____
 *							                .   ' \\| |// `.
 *								             / \\||| : |||// \
 *								           / _||||| -:- |||||- \
 *								             | | \\\ - /// | |
 *								           | \_| ''\---/'' | |
 *								            \ .-\__ `-` ___/-. /
 *								         ___`. .' /--.--\ `. . __
 *								      ."" '< `.___\_<|>_/___.' >'"".
 *							         | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *							           \ \ `-. \_ __\ /__ _/ .-` / /
 *						       ======`-.____`-.___\_____/___.-`____.-'======
 *							                      `=---='
 *
 *						     .............................................
 *							         佛祖镇楼                  BUG辟易
 *						     佛曰:
 *						             写字楼里写字间，写字间里程序员；
 *						             程序人员写程序，又拿程序换酒钱。
 *						             酒醒只在网上坐，酒醉还来网下眠；
 *						             酒醉酒醒日复日，网上网下年复年。
 *						             但愿老死电脑间，不愿鞠躬老板前；
 *						             奔驰宝马贵者趣，公交自行程序员。
 *						             别人笑我忒疯癫，我笑自己命太贱；
 *						             不见满街漂亮妹，哪个归得程序员？
 */

/*
线性查找: linear search
C / C++
*/

//1.1.1 C linear search
char* strchr(char* s, int c) {
	while (*s != '\0' && *s != c) {
		++s;
	}
	return *s == c ? s : (char*)0;
}

//所查找的数据结构单一,只有某个char
// 改进查找方案,添加指向序列结尾的指针

char* findi(char* first, char* last, int c) {
	while (first != last && *first != c) {
		++first;
	}
	return first;
}
/*
* @ 由此findi对应的查找方法可写为:
 char A[N]
 char* result=findi(A,A+N,c)
 if (result==c){//successful}
 else {//failure}
*/

//1.1.2 range:
/*
区间 range[first,last)
*/

//1.1.3 C++ linear search 采用泛型
template<class Iterator, class T>
Iterator find(Iterator first, Iterator last, const T& vaule) {
	while (first != last && *first != value) {
		++first;
	}
	return first;
}

//1.1.4 Linked list search
struct int_node {
	int val;
	int_node* next;
};

/* 
* 后续操作是遍历链表:
 int_node*p;
 for (p=list_head;p!=NULL;p=p->next){
 执行语句
 }
*/

//需要重载运算使得查找对象为 p 到 p->next
template<class Node>
struct node_wrap {
	Node* ptr;

	node_wrap(Node*p=0):ptr(p){}
	Node& operator *() const { return *ptr; }
	Node* operator ->() const { return ptr; }
	
	node_wrap& operator ++() { ptr = ptr->next; return *this; }
	node_wrap operator ++(int) { node_wrap tmp = *this; ++* this; return tmp; }

	bool operator==(const node_wrap& i) const { return ptr == i.ptr; }
	bool operator!=(const node_wrap& i) const { return ptr != i.ptr; }

	//定义一个相等运算符,用来比较 int_node 和 int:
	
};
bool operator == (const int_node& node, int n) {
	return node.val == n;
}
//调用函数 find(node_wrap<int_node>(list_head),node_wrap<int_node>(),val)
//node_wrap<int_node>() 使用了缺省构造函数, 值为 NULL 即链表最后一个next指针的值.

//1.2 concept and modeling


int main() {
	
}