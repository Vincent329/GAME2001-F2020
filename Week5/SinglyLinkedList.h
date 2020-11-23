#pragma once
#include <cassert>

template <class T> class LinkIterator;
template <class T> class LinkedList;

// define a node
template <class T>
class LinkNode
{
public:
	// Give access to the private member variables
	// by making these friend classes, the Link Iterator and linked List classes will now have access to m_data and m_next
	friend class LinkIterator<T>;
	friend class LinkedList<T>;
private:
	// no inheritance, but we want to make sure we can access this
	T m_data;
	LinkNode* m_next; // pointer to the next node
};

// Define our Iterator
// Be used to access, manipulate, and traverse the different parts of our linked list
// all it is it's a pointer object that points to a node
template <class T>
class LinkIterator
{
public:
	// define our operations that we can do
	// CONSTRUCTOR
	LinkIterator()
	{
		m_node = NULL;
	}
	// DESTRUCTOR
	~LinkIterator()
	{

	}

	// ------------ OVERLOADED OPERATORS------------------
	// assignment operator (=)
	void operator=(LinkNode<T>* node)
	{
		m_node = node; // whenever I use the equal operator, it's going to set what i passed in equal to the current node I'm pointing to now
	}
	// dereferencing operator (*)
	// we're saying, let's take what this is pointing to and grab the data where it's pointing to
	T& operator*()
	{
		assert(m_node != NULL);
			return m_node->m_data; // this is where the friend class declaration is helpful so we have access to this
								   // when we dereference a link iterator, we'll have access to the data inside
	}

	// incremental operator (++) -- prefix and postfix(
	void operator++() // prefix doesn't pass in anything as a parameter
	{
		assert(m_node != NULL);// we want to point to the next node in my singly list
			m_node = m_node->m_next; // pointing to the next part of data
	}
	void operator++(int) // postfix passes in a dummy int
	{
		assert(m_node != NULL); // we want to point to the next node in my singly list
			m_node = m_node->m_next; // pointing to the next part of data
									 // grabbing the next pointer, which basically points it over to the next pointer
	}

	// comparison operator (!= % ==)
	bool operator!=(LinkNode<T>* node)
	{
		return (m_node != node);
	}

	bool operator==(LinkNode<T>* node)
	{
		return (m_node == node); // comparing those two things together to see if they are equivalent
	}
private:
	LinkNode<T>* m_node; // points to a node in the linked list
};

// The actual linked list itself
// what are the properties we want to implement?
template <class T>
class LinkedList
{
public:
	// constructor
	LinkedList() : m_size(0), m_root(0), m_lastNode(0) {} // another way to set our values
	~LinkedList()
	{
		// assume we have a couple more nodes, we need to get rid of all our nodes
		// what we're going to is to pop off all our individual nodes until we go down to the root
		while (m_root) // while loop will break out once m_root is gone
		{
			Pop();
		}
	}

	// -----------POSITIONING FUNCTIONS----------------
	// ways in which we can move from the beginning of the list, or to the end of the list

	LinkNode<T>* Begin()
	{
		assert(m_root != NULL);
			return m_root;
	}

	LinkNode<T>* End()
	{
		// end is technically null
		return NULL;
	}

	LinkNode<T>* Last()
	{
		return m_lastNode;
	}

	// --------------------- END POSITIONING FUNCTIONS ----------------------
	// --------------------- LINKED LIST OPERATIONS --------------------

	// 1) push
	void Push(T newData)
	{
		// rule of thumb
		// first thing you do is create a standalone node
		// which it has some sort of data and it's going to point to null

		// create a standalone LinkNode object
		LinkNode<T>* node = new LinkNode<T>; // creating a new link node

		assert(node != NULL);
		node->m_data = newData; // fill it with data
		node->m_next = NULL;

		// Add the node to the existing linked list
		if (m_lastNode != NULL) // linked list is populated. push to the end of the list
		{
			// 2 steps
			// reroute the next node
			// change the last node
			m_lastNode->m_next = node; // current last node's next pointer becomes node
			m_lastNode = node; // make that new node the last node
								// dedicated pointer pointing the last thing in the list

		}
		else { // check if there's an empty linked list, so we set a new root node
			// set the root
			// but we have a root, and we have a last node
			// where are they both going to point to?
			// point to the exact same one node since there's only one node to work with
			m_root = node;
			m_lastNode = node;
		}

		m_size++;
	}

	// 2) pop
	void Pop() {
		assert(m_root != NULL);
			// check if there's still at least one item in our list
			// check if the pointers are properly set after the fact
			// so once the list is emptied out, the two root and last node pointers gotta point somewhere safe
			if (m_root->m_next == NULL)
			{
				delete m_root;
				m_root = NULL;
				m_lastNode = NULL;
			}
			else { // linked list has 2 or more items
				// take the iterator and traverse down the list until you reach the 2nd last part of the list
				// reset what the next pointer is pointing to, actively delete the content
				// reroute the last node to the 2nd last part of the list, which becomes our last node

				LinkNode<T>* prevNode = m_root; // start at the root

				// traverse the linked list until we reach the end
				while (prevNode->m_next != NULL && prevNode->m_next != m_lastNode)
				{
					prevNode = prevNode->m_next;
				}
				// previous while loop simply positions the pointer to 2nd last node of in the list
				delete m_lastNode; // we delete the last node, since it's a pointer, it gets rid of all that data
				prevNode->m_next = NULL; // now the node's next pointer is null
				m_lastNode = prevNode; // last node now points to prevNode

				// but now we have a prevnode that doesn't get use anymore
				prevNode = NULL; // don't need it anymore
			}
		m_size = (m_size == 0 ? m_size : m_size - 1);
	}

	// 3) get size
	int GetSize()
	{
		return m_size;
	}
private:
	// things we want to keep track of
	int m_size; // holds the size of the linked list
	LinkNode<T>* m_root; // points to the root of our linked list
	LinkNode<T>* m_lastNode; // points to the last node of the linked list
};