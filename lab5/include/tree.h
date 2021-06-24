template <class T> class Tree{
	virtual void inorder() = 0;
	virtual void preorder() = 0;
	virtual void postorder() = 0;
	virtual int search(T item) = 0;
	virtual bool remove(T item) = 0;
	virtual bool insert(T item) = 0;
};