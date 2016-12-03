#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "i18nText.h"

int main()
{
	const auto srcFile = R"(D:\模糊判断调查\images\u-20151213-5d142666-489d-4309-a355-2bbdf45a701b.png)";
	const auto srcImg = cv::imread(srcFile);
	if (!srcImg.data)
	{
		std::cerr << "can not open file " << srcFile << std::endl;
		return -1;
	}
	i18nText paiter;
	const auto font = R"(c:\windows\fonts\stsong.ttf)";
	bool success = paiter.setFont(font);
	if (!success)
	{
		std::cerr << "can not load font " << font << std::endl;
		return -1;
	}
	int x = srcImg.cols;
	while (true)
	{
		auto shImg = srcImg.clone();
		paiter.putText(shImg, L"呵呵呵！", cv::Point(x, 80), 255);
		cv::imshow("shImg", shImg);
		cv::waitKey(10);
		x-=3;
		if (x < 100)
		{
			x = shImg.cols;
		}
	}	
	return 0;
}
