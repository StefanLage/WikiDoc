var tab = ["a", "c", "b"] # Un tableau non tri�

print tab # acb

var sorter = new ComparableSorter[String] # On instancie le sorter ComparableSorter en pr�cisant le type que l'on veut trier, ici des String

sorter.sort(tab) # On trie le tableau

print tab # abc
