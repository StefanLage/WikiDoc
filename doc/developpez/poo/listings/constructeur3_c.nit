class MaClasse

	var entier: Int
	var chaine: String	

	# R��criture du constructeur par d�faut
	init(i: Int, s: String)
	do
		entier = i
		chaine = s
	end
end

var o = new MaClasse(10, "toto")
