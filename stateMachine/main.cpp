#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include <memory>

using std::string;
using std::cout;
using std::endl;

template <typename E>
constexpr auto to_underlying(E e) noexcept { return static_cast<std::underlying_type_t<E>>(e); }

class Creature {
private:
	enum class Names { FROG, PRINCE };

	struct State { virtual string response() = 0; };
	struct Frog : public State{ string response() { return "I'm Froggy"; } };
	struct Prince : public State { string response() { return "I'm Prince"; } };
	int state;
	
	std::vector<std::unique_ptr<State>> states;
    
public:
	Creature() : state(to_underlying(Names::FROG)) {
		states.push_back(std::make_unique<Frog>());
		states.push_back(std::make_unique<Prince>());
	}
	
	void greet() { cout << states[state]->response() << endl; }
	void kiss() { state = to_underlying(Names::PRINCE); }
	void hide() { state = to_underlying(Names::FROG); }	
};

int main() {
	cout << "start" << endl;
	
	std::unique_ptr<Creature> creature = std::make_unique<Creature>();
	creature->greet();
	
	creature->kiss();
	creature->greet();
	
	creature->hide();
	creature->greet();
	
	creature->hide();
	creature->greet();
	
	creature->hide();
	creature->greet();
	
	creature->hide();
	creature->greet();
	
	creature->kiss();
	creature->greet();
	
	return 0;
}
