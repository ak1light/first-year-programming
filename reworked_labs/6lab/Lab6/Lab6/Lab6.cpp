﻿#include <iostream>
#include <string>
#include <fstream>
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>

using namespace httplib;
using namespace nlohmann;
using namespace std;


void replace(string& str, const string from, string to) //замена строки в шаблоне
{
	try
	{
		int start_pos = str.find(from);
		str.replace(start_pos, from.length(), to);
	}
	catch (exception)
	{

	}
}


string read_file(string filepath) //чтение всего файла в переменную
{
	ifstream ifs(filepath);
	string content((std::istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
	return content;
}


string make_get_request(string host, int port, string get) //запрос на weathermap
{
	Client cli(host, port);

	if (auto res = cli.Get(get.c_str())) {
		if (res->status == 200) {
			return res->body;
		}
		else
			return "Error";
	}
}


void fill_template(json j, string& templ) //обработка ответа и заполнение шаблона
{
	string city = j["city"]["name"].dump();
	city = city.substr(1, city.size() - 2);
	replace(templ, "{city.name}", city);

	string cur_date = "";
	for (int i = 0; i < j["list"].size(); i++)
	{
		string date = j["list"][i]["dt_txt"].dump();
		date = date.substr(0, date.find(' '));
		if (date != cur_date)
		{
			cur_date = date;
			replace(templ, "{list.dt}", cur_date.substr(1, cur_date.size()));
			replace(templ, "{list.main.temp}", j["list"][i]["main"]["temp_max"].dump());
			string icon = j["list"][i]["weather"][0]["icon"].dump();
			icon = icon.substr(1, icon.size() - 2);
			replace(templ, "{list.weather.icon}", icon);
		}
	}
}


void gen_response(const Request& req, Response& res)  //вызврат результата
{
	string templ = read_file("Weather.html");
	string API_TOKEN = "f9b767474db55c749112c6af44ed179f"; // API-TOKEN
	string city = "Simferopol";
	string responce = make_get_request("api.openweathermap.org", 80, "/data/2.5/forecast?q=" + city + "&appid=" + API_TOKEN + "&units=metric");
	json j = json::parse(responce);

	fill_template(j, templ);

	res.set_content(templ, "text/html");
}

int main() 
{
	Server svr;
	svr.Get("/", gen_response);
	svr.listen("localhost", 3000);
}