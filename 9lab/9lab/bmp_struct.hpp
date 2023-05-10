#pragma once

namespace el
{
#pragma pack(1) // ��������� ������������
	struct BMPHEADER
	{
		unsigned short    Type;
		unsigned int      Size;
		unsigned short    Reserved1;
		unsigned short    Reserved2;
		unsigned int      OffBits;
	};
#pragma pack()

#pragma pack(1)
	struct BMPINFO
	{
		unsigned int    Size;
		int             Width;
		int             Height;
		unsigned short  Planes;
		unsigned short  BitCount;
		unsigned int    Compression;
		unsigned int    SizeImage;
		int             XPelsPerMeter;
		int             YPelsPerMeter;
		unsigned int    ClrUsed;
		unsigned int    ClrImportant;
	};
#pragma pack()

#pragma pack(1)
	struct Pixel
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
	};
#pragma pack()

	class BMP
	{
	public:

		BMP()
		{

		}

		void Read()
		{


			// ������ �����
			std::ifstream in("pic.bmp", std::ios::binary); // ������� ���� ��� ��������� ������

			//BMPHEADER bmpHeader;
			// ������� 14 ������ ��������� � ��������� ��������� BMPHEADER
			in.read(reinterpret_cast<char*>(&m_header), sizeof(BMPHEADER));

			//BMPINFO bmpInfo; ������� � ��������� ���� :)
			in.read(reinterpret_cast<char*>(&m_info), sizeof(BMPINFO));

			m_pixel = new Pixel * [m_info.Height];
			for (int i = 0; i < m_info.Height; i++)
				m_pixel[i] = new Pixel[m_info.Width];


			for (int i = 0; i < m_info.Height; i++)
			{
				for (int j = 0; j < m_info.Width; j++)
					in.read(reinterpret_cast<char*>(&m_pixel[i][j]), sizeof(Pixel));

				if ((3 * m_info.Width) % 4 != 0)
					for (int j = 0; j < 4 - (3 * m_info.Width) % 4; j++)
					{
						char c;
						in.read(&c, 1);
					}
			}
		}




		void Entry()
		{
			// �������� ����
			std::ofstream out("out.bmp", std::ios::binary);

			int width = m_info.Width;
			int height = m_info.Height;

			// ������������ ���������
			//BMPHEADER bmpHeader_new; ���������� n_header � ��������� ����
			n_header.Type = 0x4D42; // ��� ������ BMP
			n_header.Size = 14 + 40 + (3 * width * height);
			if (width % 4 != 0)
				n_header.Size += (4 - (3 * width) % 4) * height;
			n_header.OffBits = 54;
			n_header.Reserved1 = 0;
			n_header.Reserved2 = 0;

			out.write(reinterpret_cast<char*>(&n_header), sizeof(BMPHEADER));

			// ������������ ���������� �� �����������
			//BMPINFO bmpInfo_new; ���������� n_info � ��������� ����
			n_info.BitCount = 24;
			n_info.ClrImportant = 0;
			n_info.ClrUsed = 0;
			n_info.Compression = 0;
			n_info.Height = height;
			n_info.Planes = 1;
			n_info.Size = 40;
			n_info.SizeImage = n_header.Size - 54;
			n_info.Width = width;
			n_info.XPelsPerMeter = 0;
			n_info.YPelsPerMeter = 0;

			out.write(reinterpret_cast<char*>(&n_info), sizeof(BMPINFO));

			// �������� �������
			for (int i = 0; i < n_info.Height; i++)
			{
				for (int j = 0; j < n_info.Width; j++)
					out.write(reinterpret_cast<char*>(&m_pixel[i][j]), sizeof(Pixel));

				if ((3 * n_info.Width) % 4 != 0)
					for (int j = 0; j < 4 - (3 * n_info.Width) % 4; j++)
					{
						char c = 0;
						out.write(&c, 1);
					}
			}
		}


		void Filtr()
		{



			for (int i = 0; i < m_info.Height; i++)
				for (int j = 0; j < m_info.Width; j++)
				{
					m_pixel[i][j].r = 255;
				}
		}



		~BMP()
		{
			if (m_pixel != nullptr)
			{
				for (int i = 0; i < m_info.Height; i++)   //
					delete[] m_pixel[i];
				delete[] m_pixel;
			}

			if (n_pixel)
			{
				for (int i = 0; i < n_info.Height; i++)   //
					delete[] n_pixel[i];
				delete[] n_pixel;
			}
		}


	private:
		//��� ������
		BMPHEADER m_header;
		BMPINFO m_info;
		Pixel** m_pixel = nullptr;
		//��� ������
		BMPHEADER n_header;
		BMPINFO n_info;
		Pixel** n_pixel = nullptr;
	};


}
