class Test 
	var attribut1: String = "Getter public"
	protected var attribut2: String = "Getter protected"
end

var test = new Test

print test.attribut1 #Getter public
#print test.attribut2 #Ill�gal puisque le getter implicite est d�fini comme protected
