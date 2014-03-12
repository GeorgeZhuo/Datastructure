// 2013.12.21
// zhuozhaojin

/* the declaration of Binary_tree and Binary_node */

template <class Entry>
struct Binary_node{
	/* member of a Binary_node */
	Entry data;
	Binary_node<Entry> *left;
	Binary_node<Entry> *right;

	/* constructor of a Binary_node */
	Binary_node();
	Binary_node(Entry x);
	
};

template <class Entry>
class Binary_tree{
public:  /* all methods of a Binary_tree */
	Binary_tree();
	bool empty() const;
	void preorder(void (*visit)(Entry &x));
	void inorder(void(*visit)(Entry &x));
	void posorder(void(*visit)(Entry &x));
	void recursive_preorder(Binary_node<Entry> *sub_root,
				void (*visit)(Entry &x));
	void recursive_inorder(Binary_node<Entry> *sub_root,
			       void (*visit)(Entry &x));
	void recursive_posorder(Binary_node<Entry> *sub_root,
				void (*visit)(Entry &x));
	
	//void clear();
	void search_insert(Entry &x, Binary_node<Entry> *&sub_root);
	void insert(Entry &x);
	Binary_tree(const Binary_tree<Entry> &orginal);
	Binary_tree &operator=(const Binary_tree<Entry> &orginal);
	~Binary_tree();
protected:
	Binary_node<Entry> *root;
};
