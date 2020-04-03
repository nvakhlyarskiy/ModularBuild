
#include <experimental/optional>


std::experimental::optional<bool> cmp_holder(void) {
	
	std::experimental::optional<bool> opt = 
		std::experimental::make_optional<bool>(true);
	
	return opt; 
}

int main(int argc, char ** argv) {
	exit(EXIT_SUCCESS);
}

