#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here
TEST_CASE("Test Stack me")
{
	   
	   INFO("Hint: testing Stack fialing");
		// Create a Stack to hold ints
		Stack<int> intStack;
		REQUIRE(intStack.size() == 0);

		intStack.push(0);
		intStack.push(0);
		intStack.push(2);
		intStack.push(3);
		intStack.push(3);
		intStack.push(3);

		cout<<intStack.size();

		REQUIRE((intStack.size() != 4));

		intStack.clear();

		REQUIRE(intStack.size() == 0);
		REQUIRE(intStack.isEmpty());
		REQUIRE(!intStack.pop());

		intStack.push(3);
		REQUIRE(intStack.size() == 1);
		intStack.pop();
		REQUIRE(intStack.isEmpty());

}

TEST_CASE( "Test Bag me", "[ADT Bag]" )
{
	   INFO("Hint: testing Bag");
		// Create a Bag to hold ints
		Bag<int> intBag;

		REQUIRE(intBag.size() == 0);
		REQUIRE(intBag.isEmpty());

		intBag.add(1);
		intBag.add(2);
		intBag.add(3);
		intBag.add(4);
		intBag.add(3);

		REQUIRE(intBag.contains(3));
		REQUIRE(intBag.getFrequencyOf(3) == 2);
		REQUIRE(intBag.contains(1));
		REQUIRE(intBag.getFrequencyOf(6) == 0);

		intBag.clear();

		REQUIRE(intBag.size() == 0);
		REQUIRE(intBag.isEmpty());
		REQUIRE(!intBag.contains(1));

}

TEST_CASE( "Test Stack through XMLParser", "[XMLParser]" )
{
	XMLParser myXMLParser;
	bool caught;

	REQUIRE(myXMLParser.tokenizeInputString("<outside><tag></tag><tag2></tag2></outside>"));
	REQUIRE(myXMLParser.parseTokenizedInput());

	REQUIRE(myXMLParser.tokenizeInputString("<outside><tag></tag><tag2></outside></tag2>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());

	REQUIRE(myXMLParser.tokenizeInputString("<tag1></tag1><tag2></tag2>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());

	REQUIRE(myXMLParser.tokenizeInputString("<?xml?><tag><tag/></tag>"));
	REQUIRE(myXMLParser.parseTokenizedInput());
}

TEST_CASE( "Test Bag through XMLParser, getfrequency and contains", "[XMLParser]" )
{
	XMLParser myXMLParser;

	myXMLParser.tokenizeInputString("<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From><From>Tom</From></From> <To>Alice</To> </Note>");
	myXMLParser.parseTokenizedInput();

	REQUIRE(myXMLParser.frequencyElementName("From") == 2);	
	REQUIRE(myXMLParser.frequencyElementName("To") == 1);	
	REQUIRE(myXMLParser.frequencyElementName("Note") == 1);	
	REQUIRE(myXMLParser.frequencyElementName("Tom") == 0);	

	myXMLParser.clear();

	myXMLParser.tokenizeInputString("<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From><From>Tom</From></From> <To>Alice</To> </Note>");
	myXMLParser.parseTokenizedInput();


				
}

TEST_CASE( "Test XMLParser for random spaces and individual tags", "[XMLParser]" )
{
	XMLParser myXMLParser;

	REQUIRE(!myXMLParser.tokenizeInputString(""));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

    REQUIRE(!myXMLParser.tokenizeInputString("       "));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	
    REQUIRE(!myXMLParser.tokenizeInputString("   \n    "));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();
	
    REQUIRE(myXMLParser.tokenizeInputString(" <tag /> "));
	REQUIRE(myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(!myXMLParser.tokenizeInputString("< /tag>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(!myXMLParser.tokenizeInputString(" \n <") );
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(!myXMLParser.tokenizeInputString(" <>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<tag>content<empty/></tag>"));
	REQUIRE(myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

}

TEST_CASE( "Test XMLParse lots", "[XMLParser]" )
{
	XMLParser myXMLParser;
	bool caught;

	REQUIRE(myXMLParser.tokenizeInputString(" <someTag>Content</someTag> "));
	REQUIRE(myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<?xml version =\"1.0\"?><html><head>Content here</head><body>Content here<empty src=\"f\"/></body></html>"));
	REQUIRE(myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("</tag>reversed<tag>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<tag>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("</tag>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<empty/>\n<tag>content</tag>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<tag>content<empty/>\n\n\n</tag>"));
	REQUIRE(myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<tag1>content<tag2cross></tag1></tag2cross>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<?xml?><enclosed><head>sometext</head>\n<body>sometext</body></enclosed>"));
	REQUIRE(myXMLParser.parseTokenizedInput());
	myXMLParser.clear();

}

TEST_CASE ("Testing throwing", "[XMLParser]")
{
	XMLParser myXMLParser;
	REQUIRE_THROWS(myXMLParser.frequencyElementName("test"));

	REQUIRE(myXMLParser.tokenizeInputString("<test>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	REQUIRE_THROWS(myXMLParser.frequencyElementName("doesnt matter"));
	REQUIRE_THROWS(myXMLParser.containsElementName("doesnt matter"));
	myXMLParser.clear();

	REQUIRE(!myXMLParser.tokenizeInputString("<<test>>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	REQUIRE_THROWS(myXMLParser.frequencyElementName("doesnt matter"));
	REQUIRE_THROWS(myXMLParser.containsElementName("doesnt matter"));
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("</test><test>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	REQUIRE_THROWS(myXMLParser.frequencyElementName("doesnt matter"));
	REQUIRE_THROWS(myXMLParser.containsElementName("doesnt matter"));
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("</test><test>"));
	REQUIRE(!myXMLParser.parseTokenizedInput());
	REQUIRE_THROWS(myXMLParser.frequencyElementName("doesnt matter"));
	REQUIRE_THROWS(myXMLParser.containsElementName("doesnt matter"));
	myXMLParser.clear();

	REQUIRE(myXMLParser.tokenizeInputString("<test></test>"));
	REQUIRE(myXMLParser.parseTokenizedInput());
	REQUIRE(myXMLParser.frequencyElementName("test") == 1);
	REQUIRE(myXMLParser.containsElementName("test"));
	myXMLParser.clear();

}

TEST_CASE( "Test Stack", "[ADT Stack]" )
{
	   INFO("Hint: testing Stack");
		// Create a Stack to hold ints
		Stack<int> intStack;
		REQUIRE(intStack.size() == 0);

		intStack.push(1);
		intStack.push(1);
		intStack.push(1);
		intStack.push(1);

		REQUIRE(intStack.size() == 4);

		intStack.clear();

		REQUIRE(intStack.size() == 0);

}

TEST_CASE( "Test Bag add", "[ADT Bag]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack push and size", "[ADT Stack]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;

		REQUIRE(intStack.size() == 0);


		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);

		}

}

TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
}

TEST_CASE( "Test Stack handout-0", "[XMLParser]" )
{
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 10;
		int stackSize;
		bool success = false;
		for (int i=0; i<testSize; i++) {
			intStack.push(i);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
		for (int i = testSize-1; i>=0; i--) {
			REQUIRE(intStack.isEmpty() == false);
			int elem = intStack.peek();
			REQUIRE(elem == i);
			REQUIRE(intStack.isEmpty() == false);
			intStack.pop();
		}
		REQUIRE(intStack.isEmpty() == true);
}

TEST_CASE( "Test Stack handout-1", "[XMLParser]" )
{
	   Stack<char> charStack;
	   std::string s("Hello world");
	   int i = 1;
	   for (auto c:s) {
		   charStack.push(c);
		   REQUIRE(charStack.size() == i);
		   i++;
	   }
	   for (i = 0; i < 5; i++) {
		   REQUIRE(charStack.isEmpty() == false);
		   char c = charStack.peek();
		   REQUIRE(c == s[s.length()-1-i]);
		   REQUIRE(charStack.isEmpty() == false);
		   charStack.pop();
	   }
	   REQUIRE(charStack.size() == 6);
	   charStack.clear();
	   REQUIRE(charStack.isEmpty() == true);
}

 //You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-0", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
											TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
											TokenStruct{StringTokenType::END_TAG, std::string("test")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-1", "[XMLParser]" )
{
	   INFO("Hint: tokenize multiple elements test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = { TokenStruct{StringTokenType::DECLARATION, std::string("xml version=\"1.0\" encoding=\"UTF-8\"")},
									TokenStruct{StringTokenType::START_TAG, std::string("Note")},
									TokenStruct{StringTokenType::START_TAG, std::string("From")},
									TokenStruct{StringTokenType::CONTENT, std::string("Tom")},
									TokenStruct{StringTokenType::END_TAG, std::string("From")},
									TokenStruct{StringTokenType::START_TAG, std::string("To")},
									TokenStruct{StringTokenType::CONTENT, std::string("Alice")},
									TokenStruct{StringTokenType::END_TAG, std::string("To")},
									TokenStruct{StringTokenType::END_TAG, std::string("Note")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
		
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE( "Test XMLParser parseTokenizedInput Handout-0", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test myattr='abcdef'>stuff<this_is_empty_tag/></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
											TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
											TokenStruct{StringTokenType::EMPTY_TAG, std::string("this_is_empty_tag")},
											TokenStruct{StringTokenType::END_TAG, std::string("test")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
		output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE("Test XMLParser Final Handout-0", "[XMLParser]")
{
	INFO("Hint: TestFile");
	// Create an instance of XMLParse
	XMLParser myXMLParser;
	ifstream myfile("./TestFile.txt");
	std::string inputString((std::istreambuf_iterator<char>(myfile)), (std::istreambuf_iterator<char>()));
	bool success;

	success = myXMLParser.tokenizeInputString(inputString);

//	cout << inputString;
	REQUIRE(success);


	success = myXMLParser.parseTokenizedInput();
	REQUIRE(success);

	REQUIRE(myXMLParser.containsElementName("catalog"));
	REQUIRE(myXMLParser.frequencyElementName("catalog") == 1);
	REQUIRE(myXMLParser.containsElementName("product"));
	REQUIRE(myXMLParser.frequencyElementName("product") == 1);
	REQUIRE(myXMLParser.containsElementName("catalog_item"));
	REQUIRE(myXMLParser.frequencyElementName("catalog_item") == 2);
	REQUIRE(myXMLParser.containsElementName("item_number"));
	REQUIRE(myXMLParser.frequencyElementName("item_number") == 2);
	REQUIRE(myXMLParser.containsElementName("size"));
	REQUIRE(myXMLParser.frequencyElementName("size") == 6);
	REQUIRE(myXMLParser.containsElementName("color_swatch"));
	REQUIRE(myXMLParser.frequencyElementName("color_swatch") == 15);
	
}


