#ifndef MyTree
#define MyTree

template<class T>
class Node {
public:
	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const Node<T2> &);

	Node(): freq(0), character('0'),left(NULL), right(NULL) {}
	Node(const T &frequence, const unsigned char &character_) : freq(frequence), character(character_),left(NULL), right(NULL) {}
	Node<T> *left, *right;
	T freq;
	unsigned char character;

	bool operator>(const Node<T> &);
	int operator*(const Node<T> &);
};

template<class T>
bool Node<T>::operator>(const Node<T> &other){
	return freq > other.freq;
}

template<class T>
int Node<T>::operator*(const Node<T> &other){
	cout << "entrou" << endl;
	return other.freq;
}

template<class T2>
std::ostream& operator<<(std::ostream &out, const Node<T2> &v) {
	out << "Frequencia: " << v.freq << "\n";
	out << "Caractere: " << v.character << "\n";
	out << "Caractere(int): " << (int)v.character << "\n";
	return out;
}

#endif