#include <iostream>
void func1();
void simon(int);
// TIP 要<b>Run</b>代码，请按 <shortcut actionId="Run"/> 或点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
int main() {
    int num;

    simon(10);
    std::cout << "please put apples:";
    std::cin >> num;
    std::cout <<"Now there are " << num+10 << " apples" << std::endl;
    // TIP 当文本光标位于 <b>lang</b> 变量名称处时，按 <shortcut actionId="RenameElement"/> 可以查看 CLion 如何帮助您重命名该变量。
    // auto lang = "C++";
    // std::cout << "Hello and welcome to " << lang << "!\n";
    func1();

    // for (int i = 1; i <= 5; i++) {
    //     // TIP 按 <shortcut actionId="Debug"/> 开始调试代码。我们已为您设置了一个 <icon src="AllIcons.Debugger.Db_set_breakpoint"/> 断点，但您可以随时按 <shortcut actionId="ToggleLineBreakpoint"/> 添加更多断点。
    //     std::cout << "i = " << i << std::endl;
    // }


    return 0;
    // TIP 请访问 <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a> 查看 CLion 帮助。此外，您还可以从主菜单中选择“帮助 | 学习 IDE 功能”，尝试 CLion 的交互式课次。
}

void func1() {
    std::cout << "This is func1\n";
}

void simon(int n) {
    std::cout << "Simon says there are " << n << " apples"<<  std::endl;
}