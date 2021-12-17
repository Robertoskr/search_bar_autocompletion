<h2>
  Search Bar autocompletion algorithm
</h2>
<p>
  This algorithms mimics how a search bar algorithm works, implemented with a trie 
  data structure,
  for example: 
  Universe of posibilities = {"add user", "add roberto", "add something", "delete something", "add rob", "delete somewhat"}
  When an user types: "add"
  Then will appear : {"add user", "add rob", "add roberto"} as posible autocompletions
  Its a very basic usage, but very usefull.
  
  Pd:
  obvious you could use an O(n2) algorthm, that tests with all the words, 
  but in bigger applications this is very expensive, so this gives you 
  a better O(n) runtime for searching all the possible autocompletions.
</p>
