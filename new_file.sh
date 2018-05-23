touch $1.cpp
touch $1.hpp

upper=$(echo "$1"|tr '/a-z/' '/A-Z/')

echo "#include \"$1.hpp\" 
" > "$1.cpp"

echo "#ifndef $upper
#define $upper

#include \"Component.hpp\"

class $1 : public Component{

};

#endif
" > "$1.hpp"