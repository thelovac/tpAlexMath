
//Constructeur
template <class TYPE>
List<TYPE>::List()
{
	first = NULL;
	last = NULL;
	nbElements = 0;
}

//Destructeur
template <class TYPE>
List<TYPE>::~List()
{
}

//Insert à la fin de liste (supporte l'ajout dans une liste vide)
template <class TYPE>
void List<TYPE>::PushBack(TYPE* _element)
{
	Cell<TYPE>* cell = new Cell<TYPE>(_element, NULL, NULL);
	
	if(first == NULL)
	{
		first = cell;
		last = cell;
	}
	else
	{
		cell->Previous = last;
		cell->Next = NULL;
		last->Next = cell;
		last = cell;
	}
	
	nbElements++;
}

template <class TYPE>
void List<TYPE>::Insert(TYPE* _Element, Iterator<TYPE>& _Iter)
{
    //Insert avant la position courante (limite: impossible d'ajouter à la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au début 
    //      2)Insertion entre premier et dernier 
	
	Cell<TYPE>* cell  = new Cell<TYPE>(_Element, NULL, NULL);

	if(first != NULL)
	{
		if(first->Next == NULL)
		{
			cell->Next = first;
			cell->Previous = NULL;
			first->Previous = cell;
			last = first;
			first = cell;
		}
		else
		{
			cell->Next = _Iter.GetCurrent();
			cell->Previous = _Iter.GetCurrent()->Previous;
			_Iter.GetCurrent()->Previous->Next = cell;
			_Iter.GetCurrent()->Previous = cell;
		}

		nbElements++;
	}
} 

template <class TYPE>
void List<TYPE>::Erase(Iterator<TYPE>& _Iter)
{
    //4 cas possibles... A vous de les trouver!
	if(first!=NULL)
	{
		if(first==last)
		{
			first = NULL;
			last = NULL;
		}
		else if(_Iter.GetCurrent() == first)
		{
			first = first->Next;
			first->Previous = NULL;
			delete _Iter.GetCurrent();
		}
		else if(_Iter.GetCurrent() == last)
		{
			_Iter.GetCurrent()->Previous->Next = NULL;
			last=_Iter.GetCurrent()->Previous;
			delete _Iter.GetCurrent();
			
		}
		else
		{
			_Iter.GetCurrent()->Previous->Next = _Iter.GetCurrent()->Next;
			_Iter.GetCurrent()->Next->Previous = _Iter.GetCurrent()->Previous;
			delete _Iter.GetCurrent();
		}

		nbElements--;
	}
}

template <class TYPE>
TYPE* List<TYPE>::GetElement(const Iterator<TYPE>& _Iter) const
{
	return _Iter.GetCurrentElement();
}

template <class TYPE>
int List<TYPE>::GetNbElements() const
{ 
	return nbElements;
}

template <class TYPE>
bool List<TYPE>::IsEmpty() const
{
	if(first==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
} 

template <class TYPE>
void List<TYPE>::Clear()
{
	if(first!=NULL)
	{
		Iterator<TYPE>* _i = new Iterator<TYPE>;

		_i->SetCurrent(last);

		while(first!=NULL)
		{
			if(_i->GetCurrent()->Previous == NULL)
			{
				first = NULL;
				last = NULL;		
			}
			else
			{
				_i->Previous();
				delete _i->GetCurrent()->Next;
			}
		}
	}
}

//Méthodes déjà implémentées
template <class TYPE>
Cell<TYPE>* List<TYPE>::Begin() const
{ 
    return this->first;
}

template <class TYPE>
Cell<TYPE>* List<TYPE>::End() const
{
    return this->last;
}

template <class TYPE>
ostream& operator<<(ostream& _sortie, const List<TYPE>& _list)
{
    Cell<TYPE>* cellule=_list.first;

    while(cellule != NULL){
        _sortie<<*cellule->Element<<endl;
        cellule = cellule->Next;
    }
    _sortie<<endl;
    return _sortie;
}