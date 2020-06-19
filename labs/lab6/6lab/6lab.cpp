#include <iostream>
#include <fstream>
#include <string>
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>

using namespace httplib;
using json = nlohmann::json;

//SIMFEROPOL - 693805
//API key - f9b767474db55c749112c6af44ed179f

void gen_response(const Request& req, Response& res) {

	//openweathermap.org:80/data/2.5/forecast?id=693805&APPID=f9b767474db55c749112c6af44ed179f&units=metric

	httplib::Client cli("api.openweathermap.org", 80);

	auto resp = cli.Get("/data/2.5/forecast?id=693805&APPID=f9b767474db55c749112c6af44ed179f&units=metric");
	//std::cout << resp->body;
	if (resp && resp->status == 200) {
		//res.set_content(resp->body, "text/plain");
		json result = json::parse(resp->body);
		std::cout << result["cod"];

		std::ifstream fin("Weather.html");
		std::string output = "could not load template :(";

		if (!fin.is_open()) {
			std::cout << "Ошибка при открытии макета." << std::endl;
			fin.close();
		}
		else {
			output = "";
			char ch;
			while (fin.get(ch)) {
				output += ch;
			}

			std::string name = "{city.name}";
			output.replace(output.find(name), name.length(), result["city"]["name"]);

			std::string dt = "{list.dt}";
			std::string temp = "{list.main.temp}";
			std::string icon = "{list.weather.icon}";

			std::string date_check = "";
			std::cout << result["list"].size() << std::endl;
			std::cout << result["list"][1]["main"]["temp"];
			std::cout << result["list"][1]["weather"][0]["icon"].dump() << std::endl;
			int amt = result["list"].size();
			for (int i = 0; i < result["list"].size(); i++) {
				if (output.find(dt) != std::string::npos) {
					if (result["list"][i]["dt_txt"].dump().substr(1, 11) != date_check) {
						output.replace(output.find(dt), dt.length(), result["list"][i]["dt_txt"].dump().substr(1, 11));

						if (output.find(temp) != std::string::npos) {
							output.replace(output.find(temp), temp.length() + 1, result["list"][i]["main"]["temp"].dump());
						}

						if (output.find(icon) != std::string::npos) {
							std::string iconid = result["list"][1]["weather"][0]["icon"].dump();
							std::string url = "http://openweathermap.org/img/wn/" + (iconid.substr(1, iconid.size() - 2) + ".png");

							output.replace(output.find(icon), icon.length(), url);
						}

						date_check = result["list"][i]["dt_txt"].dump().substr(1, 11);
						std::cout << " " << i << std::endl;
					}
				}
			}

		}

		res.set_content(output, "text/html");
	}
	else {
		res.set_content("somethings wrong, i can feel it", "text/text");
	}
}



int main(void) {
	setlocale(LC_ALL, "Russian");
	Server svr;                    // Создаём сервер (пока-что не запущен)
	svr.Get("/", gen_response);    // Вызвать функцию gen_response если кто-то обратиться к корню "сайта"
	svr.listen("localhost", 3000); // Запускаем сервер на localhost и порту 3000
}