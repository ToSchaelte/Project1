#include <iostream>

using namespace std;

int main()
{
	int maxValue = 10;

	for (int a = 0; a < maxValue; ++a)
	{
		for (int b = 0; b < maxValue; ++b)
		{
			for (int c = 0; c < maxValue; ++c)
			{
				for (int d = 0; d < maxValue; ++d)
				{
					for (int e = 0; e < maxValue; ++e)
					{
						for (int f = 0; f < maxValue; ++f)
						{
							for (int g = 0; g < maxValue; ++g)
							{
								for (int h = 0; h < maxValue; ++h)
								{
									for (int i = 0; i < maxValue; ++i)
									{
										for (int j = 0; j < maxValue; ++j)
										{
											int top_left		= a * 1000 + b * 100 + c * 10 + d;
											int top_mid			=					   e * 10 + f;
											int top_right		=			 e * 100 + g * 10 + d;
											int mid_left		= h * 1000 + i * 100 + j * 10 + e;
											int mid_mid			= h * 1000 + i * 100 + b * 10 + g;
											int mid_right		=					   f * 10 + e;
											int bottom_left		= j * 1000 + i * 100 + d * 10 + b;
											int bottom_mid		= h * 1000 + i * 100 + d * 10 + f;
											int bottom_right	= c * 1000 + g * 100 + g * 10 + c;

											if (top_mid == 0)
											{
												continue;
											}

											if (top_left / top_mid == top_right)
											{
												if (mid_left - mid_mid == mid_right)
												{
													if (bottom_left - bottom_mid == bottom_right)
													{
														if (top_left - mid_left == bottom_left)
														{
															if (top_mid + mid_mid == bottom_mid)
															{
																if (top_right * mid_right == bottom_right)
																{
																	cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = "
																		<< d << ", e = " << e << ", f = " << f << ", g = " << g << ", h = "
																		<< h << ", i = " << i << ", j = " << j << endl;
																}
															}
														}
													}
												}
												
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}