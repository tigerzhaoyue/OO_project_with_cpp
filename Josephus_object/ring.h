struct Boy{
	int code;
	Boy* next;
};

class Ring{
public:
	Ring(int n);
	void Count(int m);	//count m children
	void PutBoy();		//cout the current Boy number
	void ClearBoy();	//remove the current boy form the list
	~Ring();
protected:
	Boy* pBegin;
	Boy* pivot;
	Boy* pCurrent;
};
