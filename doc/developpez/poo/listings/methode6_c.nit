class MaClasse
	fun +(i: Int): String 
	do
		return "J'ajoute {i} � l'objet de type MaClasse..."
	end
end

var o = new MaClasse
print o+10
