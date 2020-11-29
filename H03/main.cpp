void Hand::Sort()
{
  // loop to sort cards
  for(int i=0,i<Size(); i++)
  {
    for(int j=0,j<Size()-1; j++)
    {
      
    if(Cards[i]->rank > Cards[i+j]->rank)
    {
      cout <<"Swapping"<<endl;    
      Card*temp =Cards[i]
       Cards[i] = Cards[i+j];
      Cards[i+j] = temp;
      
    }
  }   
}
