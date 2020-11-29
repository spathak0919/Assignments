void Hand::Sort()
{

  for(int i=0,i<Size(); i++)
  {
    if(Cards[i]->rank > Cards[j]->rank)
    {
      cout <<"Swap";
      Card*temp =Cards[i]
       Cards[i] = Cards[j];
      Cards[j] = temp;
      
    }
  }   
}
