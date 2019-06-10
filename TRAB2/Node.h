#ifndef MyTree
#define MyTree

template<class F, class C>
class Node {
public:
	Node(const F &frequence, const C &character_) : freq(frequence), character(character_),left(NULL), right(NULL) {}
	Node<F, C> *left, *right;
	F freq;
	C character;
};


#endif