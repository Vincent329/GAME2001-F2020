#pragma once
#include <cassert>

template <class T> class LinkIterator;
template <class T> class LinkedList;

// define a node -> ASSIGNMENT REQUIREMENT

template <class T>
class LinkNode
{
public:
	// Give access to the private member variables
	// by making these friend classes, the Link Iterator and linked List classes will now have access to m_data and m_next
	friend class LinkIterator<T>;
	friend class LinkedList<T>;
	int GetPriority()
	{
		return priority;
	}
	T getData()
	{
		return m_data;
	}
	LinkNode* GetNext()
	{
		return m_next;
	}
	LinkNode* GetPrevious()
	{
		return m_previous;
	}

private:
	T m_data;
	int priority; // priority queue, ASSIGNMENT REQUIREMENT

	LinkNode* m_next; // 
	LinkNode* m_previous; // DOUBLY LINKED LIST EXCLUSIVE (now we can go forward backward through the list
};

// Define our Iterator
// Be used to access, manipulate, and traverse the different parts of our linked list
// all it is it's a pointer object that points to a node
template <class T>
class LinkIterator
{
public:
	friend class LinkedList<T>; // New Addition to define the linked list as a friend to access linked list functions
	
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

	// Decremental operator (--) -- prefix and postfix
	void operator--() // prefix doesn't pass in anything as a parameter
	{
		assert(m_node != NULL);// we want to point to the next node in my singly list
		m_node = m_node->m_previous; // pointing to the previous part of data
	}
	void operator--(int) // postfix passes in a dummy int
	{
		assert(m_node != NULL); // we want to point to the next node in my singly list
		m_node = m_node->m_previous; // pointing to the previous part of data
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

	// getter for the node
	LinkNode<T>* GetNode()
	{
		return m_node;
	}

	// Week 9 addition
	bool isValid()
	{
		return (m_node != NULL); // if it's null then you have to adjust
	}

private:
	LinkNode<T>* m_node; // points to a node in the linked list
};

//--------------------- PRIORITY QUEUE LINKED LIST------------------------
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
		return m_root; // returns root node
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


	// --------------------- BEGIN PRIORITY QUEUE FUNCTIONS --------------------
	// inserting before and Inserting after
	// whenever we have a node, there's a priority value that inserts the node at the appropriate location depending on that priority value
	// give ourselves the ability to insert into queue before or after what the iterator is pointing to

	void Insert_Before(LinkIterator<T>& it, T newData, int priorityOrder = 0)
	{ 
		assert(it.m_node != NULL);
		
		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);
		// recall that LinkNode has a pointer to what's next and what's previous
		// in the case of this function, insert the new node to before where the iterator is pointing to

		node->m_data = newData; // give the data
		node->priority = priorityOrder;
		node->m_next = it.m_node; // next pointer of new node is going to point to 
		node->m_previous = it.m_node->m_previous; // wherever the iterator's previous node was pointing to becomes the new node's previous pointer

		// point the previous node to the new node
		if (node->m_previous != NULL)
		{
			node->m_previous->m_next = node; // so the previous pointer's next pointer is going to point to the new node
			
		}
		it.m_node->m_previous = node; // change the pointed iterator's previous node to the new node
		
		// now check if the iterator was pointing to the root
		if (it.m_node == m_root)
		{
			m_root = node;
		}
		m_size++; // remember to increase the max size
	}

	void Insert_After(LinkIterator<T>& it, T newData)
	{
		assert(it.m_node != NULL);
		
		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		// similar functionality to insert before, just with flipped logic to account for what's next to the iterator
		node->m_data = newData;
		node->m_next = it.m_node->m_next; // if the next pointer is null, it's null
		node->m_previous = it.m_node;

		if (node->m_next != NULL)
		{
			node->m_next->m_previous = node;
		}
		it.m_node->m_next = node;

		if (it.m_node == m_lastNode)
		{
			m_lastNode = node;
		}
		m_size++;
	}

	// haven't done anything with the priority queue itself yet, we're just making helper functions
	// ------------------ END PRIORITY QUEUE LINKED LIST FUNCTIONS------------------------
	
	// --------------------- LINKED LIST OPERATIONS --------------------

	// Push to the front of list (Double Ended exclusive)
	void Push_Front(T newData)
	{
		// create a new node (new ROOT NODE)
		LinkNode<T>* node = new LinkNode<T>; // creating a new link node AND set it with its new data

		assert(node != NULL);
		node->m_data = newData;
		node->m_next = NULL;
		node->m_previous = NULL;

		// QUESTION, are there objects in the list? if there are, then we have to reroute
		// if not, it's just the root node
		// take the next of the root node then point it to the previous old root, then make it the new root

		if (m_root != NULL) { // linked list has at least one item
			node->m_next = m_root; // next pointer of node points to the current root
			m_root->m_previous = node; // before we change root nodes, make sure that the node's previous pointer points to the new node before the new node becomes root
			m_root = node; // make this current node the new root
		}
		else { // if the list is empty
			m_root = node;			// root and last node are just simply the node
			m_lastNode = node;		// no need to change anything
		}
		m_size++;
	}

	// POPPING FROM THE FRONT
	void Pop_Front()
	{
		assert(m_root != NULL); // ASSUMING THAT THERE'S STILL SOMETHING IN THE LIST

		// eventually deleting the contents of the temporary pointer
		LinkNode<T>* temp = m_root;

		// reroute my pointers
		m_root = m_root->m_next; // set the new root to the next thing

		if (m_root != NULL)
		{
			m_root->m_previous = NULL;
		}
		else {
			m_lastNode = NULL;
		}
		delete temp; // Doesn't remove pointer, but removes content in what the pointer is referring to
		temp = NULL;

		// BOOK ERROR!
		// Check to see if the list is empty

		if (m_root == NULL)
		{
			m_lastNode == NULL; // good practice to clear out everything
		}
		m_size = (m_size == 0 ? m_size : m_size - 1);
	}


	// 1) push
	void Push(T newData, int priorityOrder = 0)
	{
		// rule of thumb
		// first thing you do is create a standalone node
		// which it has some sort of data and it's going to point to null

		// create a standalone LinkNode object
		LinkNode<T>* node = new LinkNode<T>; // creating a new link node

		assert(node != NULL);
		node->priority = priorityOrder;
		node->m_data = newData; // fils in data
		node->m_next = NULL; // next pointer 
		node->m_previous = NULL; // safety net

		// Add the node to the existing linked list
		if (m_lastNode != NULL) // linked list is populated. push to the end of the list
		{
			// 2 steps
			// reroute the next node
			// change the last node
			m_lastNode->m_next = node; // current last node's next pointer becomes node
			node->m_previous = m_lastNode; // since we haven't changed what the last node actually is yet, we're pointing to the current last node as our previous
		}
		else { // check if there's an empty linked list, so we set a new root node
			// set the root
			// but we have a root, and we have a last node
			// where are they both going to point to?
			// point to the exact same one node since there's only one node to work with
			m_root = node;
		}
		m_lastNode = node; // make that new node we placed as the last node
							// dedicated pointer pointing the last thing in the list
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


			// no need to traverse like the other linked lists, we can do our own thing
			// we can go right to the end

			LinkNode<T>* prevNode = m_lastNode->m_previous; // make this previous node the node just before the last node

			// previous while loop simply positions the pointer to 2nd last node of in the list
			prevNode->m_next = NULL; // make the next node of the 2nd last node null
			delete m_lastNode; // delete the contents of last node
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