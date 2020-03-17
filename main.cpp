#include <iostream>
#include "magabe_parser.h"

using namespace std;

void run_example();


int main()
{

  cout <<  digit().firstStringMatch("A1C") << endl;
  cout <<  any(chaR('!'),"o").star().firstStringMatch("Hellow!")<< endl;

    //example
     run_example();

    return 0;
}
void run_example(){
    cout << ">>>>> EXAMPLE\n\n" << endl;

    std::string str = ""
                  "<tag attr1=\"attribute1\"> Text </tag>"
                  "<TAG> TEXT </TAG>"
                  "<i></i>"
                  "<b/>"
                  "<v href=\"qwety\"/>"
                  "";

    Parser anyElement = (spaceOptional().seq(spaceOptional().seq(chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>'))).seq(spaceOptional()) & (spaceOptional().seq(spaceOptional().seq (chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>')))
                                                                                                                                                                      .seq(spaceOptional()).seq((spaceOptional().seq(spaceOptional().seq (chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>')))
                                                                                                                                                                                                                     .seq(spaceOptional()).seq(any(spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>')))
                                                                                                                                                                                                                                                   .seq(spaceOptional()),"<>").plus()).seq(spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>')))
                                                                                                                                                                                                                                                                                           .seq(spaceOptional()))).seq(spaceOptional()) | spaceOptional().seq(spaceOptional().seq (chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>'))).seq(spaceOptional()).seq(spaceOptional()).seq(spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>')))
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          .seq(spaceOptional()))).seq(spaceOptional()) | spaceOptional().seq(chaR('<').seq(any(chaR('/').seq(chaR('>')),"<>").plus()).seq(chaR('/').seq(chaR('>'))))
                                                                                                                                                                                                 .seq(spaceOptional())).plus()).seq(spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>'))).seq(spaceOptional()))).seq(spaceOptional())  | spaceOptional().seq(spaceOptional().seq (chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>')))
                                                                                                                                                                                                                                                                                                                                                                                                                                 .seq(spaceOptional()).seq(any(spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>'))).seq(spaceOptional()),"<>").plus()).seq(spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>'))).seq(spaceOptional())))
                                                                                                                                                  .seq(spaceOptional()) | spaceOptional().seq(spaceOptional().seq (chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>'))).seq(spaceOptional()).seq(spaceOptional()).seq(spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>'))).seq(spaceOptional())))
                                                                                                                                                  .seq(spaceOptional()) | spaceOptional().seq(chaR('<').seq(any(chaR('/').seq(chaR('>')),"<>").plus()).seq(chaR('/').seq(chaR('>')))).seq(spaceOptional()) | spaceOptional().seq (chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>'))).seq(spaceOptional()) | word().plus() | chaR('<').seq(chaR('!')).seq(chaR('-')).seq(chaR('-'))
                                                                                                                                                  .seq(any(chaR('-').seq(chaR('-')).seq(chaR('>'))).star()).seq(chaR('-').seq(chaR('-')).seq(chaR('>'))))
                                             .star() & spaceOptional().seq(chaR('<').seq(chaR('/')).seq(spaceOptional()).seq(word().plus()).seq(spaceOptional()).seq(chaR('>')))
                                             .seq(spaceOptional())).seq(spaceOptional())).oR(spaceOptional().seq(chaR('<').seq(any(chaR('/').seq(chaR('>')),"<>").plus()).seq(chaR('/').seq(chaR('>'))))
                                                                                             .seq(spaceOptional()) | spaceOptional().seq (chaR('<').seq(any(chaR('>'),"/").star()).seq(chaR('>'))).seq(spaceOptional()) | chaR('<').seq(chaR('!')).seq(chaR('-')).seq(chaR('-')).seq(any(chaR('-').seq(chaR('-')).seq(chaR('>'))).star()).seq(chaR('-').seq(chaR('-')).seq(chaR('>'))));




   for(auto m : anyElement.allStringMatches(str)){
       cout << m <<" <<<<<<"<< endl;
   } //prints ("<tag attr1=\"attribute1\"> Text </tag>", "<TAG> TEXT </TAG>", "<i></i>", "<b/>", "<v href=\"qwety\"/>")

     cout << "\n\n <<<<<" << endl;
}

