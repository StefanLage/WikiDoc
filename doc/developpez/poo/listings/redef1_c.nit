class ClasseMere
	fun methode 
	do
		print "M�thode originale"
	end
end

class ClasseFille
	super ClasseMere

	redef fun methode 
	do
		print "M�thode red�finie"
	end
end

var o = new ClasseFille
o.methode #M�thode red�finie
