/*
* Example from https://uk.wikipedia.org/wiki/%D0%A1%D0%BF%D0%BE%D1%81%D1%82%D0%B5%D1%80%D1%96%D0%B3%D0%B0%D1%87_(%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD_%D0%BF%D1%80%D0%BE%D1%94%D0%BA%D1%82%D1%83%D0%B2%D0%B0%D0%BD%D0%BD%D1%8F)
*/

#include <iostream>
#include <string>
#include <set>

class SupervisedString;

class ISupervisedStringObserver {
public:
	virtual void handleEvent (const SupervisedString&) = 0;
};

class SupervisedString{
	std::string _str;
	std::set<ISupervisedStringObserver*> _observers;
  
	void _Notify() {
		std::cout << "Notify ALL" << std::endl;
		for (auto &iter : _observers) {
			//iter.second->handleEvent (*this);
			iter->handleEvent (*this);
		}
	}
public:
	void add_observer (ISupervisedStringObserver& ref) { _observers.insert(&ref); }
	
	void remove_observer (ISupervisedStringObserver& ref) { _observers.erase(&ref); }
	
	const std::string& get() const { return _str; }
	
	void reset (std::string str) {
		_str = str;
		_Notify();
	}
};

/**
* Print trackable string in std::cout
*/
class Reflector : public ISupervisedStringObserver{
public:
	virtual void handleEvent (const SupervisedString& ref) { std::cout << "string is: "<< ref.get() << std::endl; }
};

/**
* Print trackable string length in std::cout
*/
class Counter: public ISupervisedStringObserver{
	virtual void handleEvent (const SupervisedString& ref) { std::cout << "length = " << ref.get().length() << std::endl; }
};

int main(){
	std::cout << "OBSERVER" << std::endl;
    
	SupervisedString str;
    
	Reflector refl;
	Counter cnt;

	str.add_observer (refl);
	str.add_observer (cnt);
  
	str.reset ("Hello, again!");
	std::cout<<std::endl;

	str.remove_observer (refl);
	str.reset ("Google");
	std::cout<<std::endl;

	return 0;
}



