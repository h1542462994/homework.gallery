#include<iostream>
#include<vector>
#include<string>
#include"Context.h"
#include"App.h"

using namespace std;

int main() 
{
	Context context;
	DApp app(&context);
	app.run();

}