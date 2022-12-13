#include <iostream>

using namespace std;

int main()
{
	int maxValue = 10;

	for (int a = 0; a < maxValue; ++a)
	{
		for (int b = 0; b < maxValue; ++b)
		{
			if (b == a)
			{
				continue;
			}
			for (int c = 0; c < maxValue; ++c)
			{
				if (c == a || c == b)
				{
					continue;
				}
				for (int d = 0; d < maxValue; ++d)
				{
					if (d == a || d == b || d == c)
					{
						continue;
					}
					for (int e = 0; e < maxValue; ++e)
					{
						if (e == a || e == b || e == c || e == d)
						{
							continue;
						}
						for (int f = 0; f < maxValue; ++f)
						{
							if (f == a || f == b || f == c || f == d || f == e)
							{
								continue;
							}
							for (int g = 0; g < maxValue; ++g)
							{
								if (g == a || g == b || g == c || g == d || g == e || g == f)
								{
									continue;
								}
								for (int h = 0; h < maxValue; ++h)
								{
									if (h == a || h == b || h == c || h == d || h == e || h == f || h == g)
									{
										continue;
									}
									for (int i = 0; i < maxValue; ++i)
									{
										if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h)
										{
											continue;
										}
										for (int j = 0; j < maxValue; ++j)
										{
											if (j == a || j == b || j == c || j == d || j == e || j == f || j == g || j == h || j == i)
											{
												continue;
											}
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