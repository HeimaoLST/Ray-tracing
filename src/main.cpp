#include <iostream>

int main() {
    int weight = 256;
    int height = 256;
    std::cout<<"P3\n"<<weight<<' '<<height<<"\n255\n";
    for (int i = 0; i < weight; i++) {
        std::clog<<"Row Remaining: "<<weight - i<<'\n';
        for (int j = 0; j < height;j++) {

            auto rr = double(i) / (weight - 1);
            auto rg = double(j) / (height - 1);
            auto rb = 0;
            int r = rr * 255.99;
            int g = rg * 255.99;
            int b = rb * 255.99;

            std::cout<<r<<' '<<g<<' '<<b<<'\n';
        }
    }
    std::clog<<"Done!\n";
}
