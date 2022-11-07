#pragma once

using namespace System;
using namespace System::Data::SqlClient;


public ref class User {
public:
	int id;
	String^ name;
	String^ email;
	String^ prn;
	String^ password;

};



