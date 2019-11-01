#include "test.h"

void test()
{
    testMStack();
    testMChatString();
    testMCharStringLink();
}

void testMStack()
{
    MStack<int> stack;
    //test push
    assert(stack.push(1));
    assert(stack.push(2));

    //test pop
    assert(stack.pop() == 2);

    //test top
    assert(stack.top() == 1);

    //test isEmpty
    assert(!stack.isEmpty());
}

void testMChatString()
{
    std::string cstring1 = "cstring1";
    char string1[] = "string1";

    //测试构造函数1
    MCharString charstring1;
    //std::cout << "success create 1" << std::endl;

    //测试init
    charstring1.init(cstring1);
    //std::cout << "success create 1" << std::endl;

    //测试构造函数2
    MCharString charstring2(cstring1);
    //std::cout << "success create 2" << std::endl;

    //测试构造函数3
    MCharString charstring3(string1);
    //std::cout << "success create 3" << std::endl;

    //测试构造函数4
    MCharString charstring4(7, string1);
    //std::cout << "success create 4" << std::endl;

    //测试构造函数5
    MCharString charstring9("abcdefg");
    //charstring9.print();

    //测试size()
    assert(charstring1.size() == 8);
    //std::cout << "success test size 1" << std::endl;
    assert(charstring2.size() == 8);
    //std::cout << "success test size 2" << std::endl;
    assert(charstring3.size() == 7);
    //std::cout << "success test size 3" << std::endl;
    assert(charstring4.size() == 7);
    //std::cout << "success test size 4" << std::endl;

    //测试length()
    assert(charstring1.length() == 8);
    //std::cout << "success test length 1" << std::endl;
    assert(charstring2.length() == 8);
    //std::cout << "success test length 2" << std::endl;
    assert(charstring3.length() == 7);
    //std::cout << "success test length 3" << std::endl;
    assert(charstring4.length() == 7);
    //std::cout << "success test length 4" << std::endl;

    //测试重载运算符[]
    assert(charstring1[0] == 'c');
    assert(charstring1[7] == '1');

    //测试print()
    //charstring1.print();
    //charstring2.print();
    //charstring3.print();
    //charstring4.print();

    //测试indexof()
    assert(charstring1.indexof(charstring3) == 1);

    //测试substring()
    MCharString charstring5 = charstring1.substringBypos(1, 7);
    assert(charstring5[0] == 's');
    assert(charstring5[6] == '1');
    assert(charstring5.length() == 7);

    //测试重载赋值运算符=
    MCharString charstring6 = charstring5;
    assert(charstring5[0] == 's');
    assert(charstring5[6] == '1');
    assert(charstring5.length() == 7);

    //测试重载比较运算符
    assert(charstring1 == charstring2);
    assert(charstring1 != charstring3);
    assert(charstring1 < charstring3);
    assert(charstring5 > charstring2);

    //测试重载二元运算符+
    MCharString charstring7 = charstring1 + charstring3;
    assert(charstring7.length() == 15);
    assert(charstring7[7] == '1');
    assert(charstring7[8] == 's');

    //测试concat()
    charstring2.concat(charstring3);
    assert(charstring2 == charstring7);

    //测试append()
    charstring1.append(charstring3);
    assert(charstring1 == charstring2);

    //测试push_back()
    charstring2.push_back('2');
    assert(charstring2.size() == 16);

    //测试at()
    for (int i = 0; i < charstring1.size(); i++) {
        assert(charstring1[i] == charstring1.at(i));
    }

    //测试assign()
    MCharString charstring8;
    charstring8.assign(charstring1);
    assert(charstring1 == charstring8);
}

void testMCharStringLink()
{
    std::string string1 = "abcdefg";
    std::string string2 = "hijklmn";
    std::string string3 = "opqrst";
    std::string string4 = "uvwxyz";
    MCharString charstring1(string1);
    MCharString charstring2(string2);
    MCharString charstring3(string3);
    MCharString charstring4(string4);

    //测试MCharStringNode构造函数1
    MCharStringNode node1;

    //测试MCharStringNode setelement()
    node1.setelement(charstring1);

    //测试MCharStringNode构造函数2
    MCharStringNode node2(charstring2);

    //test append()
    MCharStringLink link;
    link.append(charstring1);
    link.append(charstring2);
    link.append(charstring3);

    //test remove()
    assert(link.remove(charstring2));
    assert(!link.remove(charstring4));

    //test search()
    assert(link.search(charstring3));
    assert(!link.search(charstring2));

    //test print()
    //link.print();
}

void testParser()
{
    //测试构造函数
    std::string filepath = "./input/19.html";
    Parser parser(filepath);

    //测试getTitle()
    assert(parser.getTitle());
    assert(parser.getInfo());
    assert(parser.getSummary());
    assert(parser.outputFilmInfo("./output/19.info"));
    Dic dic("./dic/dic");
    parser.wordSegmentation(dic);
    assert(parser.outputWordSeg("./output/19.txt"));
}

void testDic()
{
    Dic dic("./dic/dic");
    assert(dic.size() == 275909);
    assert(dic.find("龟年鹤寿"));
}
void testFiles()
{
    Files files("./input/");
    //files.print();

}
