#ifndef ABBINARYNODE_H
#define ABBINARYNODE_H


class AbBinaryNode
{
    public:
        AbBinaryNode();
        AbBinaryNode(int &nodeItem, int left, int right);
        virtual ~AbBinaryNode();

        int item;
        int right;
        int left;

    protected:

    private:
};

#endif // ABBINARYNODE_H
