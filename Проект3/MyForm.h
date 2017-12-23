#pragma once
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
char tmp_map[24][32];
char map[24][32] = { // 24 столба 32 строки 

	"+###################+",
	"|         #         |",
	"| ## #### # #### ## |",
	"| ## ####   #### ## |",
	"|                   |",
	"|       #####       |",
	"|     #   #   #     |",
	"|     ### # ###     |",
	"|     #       #     |",
	"|##               ##|",
	"|## # ###   ### # ##|",
	"|   # #       # #   |",
	"|   # ######### #   |",
	"|## #           # ##|",
	"|##   #########   ##|",
	"|         #         |",
	"|    #### # ####    |",
	"|                   |",
	"|#  #   #####   #  #|",
	"|#  #     #     #  #|",
	"|   #     #     #   |",
	"| #####   #   ##### |",
	"|                   |",
	"+###################+"
};




struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};

vector<target> walk_queue;

vector<walk> BFSArray;

void AddArray(int x, int y, int wc, int back) // Добавить в очередь
{
	if (tmp_map[y][x] == ' ' || tmp_map[y][x] == '.')// ограничения от выхода за пределы карты Пк
	{
		tmp_map[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back(tmp);
	}
}

void FindPath(int sx, int sy, int x, int y) // ищет игрока 
{
	memcpy(tmp_map, map, sizeof(map));
	BFSArray.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back(tmp);

	int i = 0;
	while (i < BFSArray.size())
	{
		if (BFSArray[i].x == x && BFSArray[i].y == y)
		{
			walk_queue.clear();
			target tmp2;
			while (BFSArray[i].walk_count != 0) {
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back(tmp2);

				i = BFSArray[i].back;
			}

			break;
		}

		AddArray(BFSArray[i].x + 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
		AddArray(BFSArray[i].x - 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
		AddArray(BFSArray[i].x, BFSArray[i].y + 1, BFSArray[i].walk_count + 1, i);
		AddArray(BFSArray[i].x, BFSArray[i].y - 1, BFSArray[i].walk_count + 1, i);
		i++;
	}

	BFSArray.clear();
}

namespace Проект3 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		static MyForm^ TheInstance;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			TheInstance = this;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		/////////////////////////////////////////////////////////////////КНОПКИ////////////////////////
	public: System::Windows::Forms::Label^  label1;//карта
	private:
	private: System::Windows::Forms::Button^  button1;//старт

	private:

	public: System::Windows::Forms::Label^  label4;//инструкция
	public: System::Windows::Forms::TextBox^  textBox1;//поле для ввода сложности
	private: System::Windows::Forms::Button^  button2;//вверх
	public:
	private: System::Windows::Forms::Button^  button3;//влево
	private: System::Windows::Forms::Button^  button4;//вниз
	private: System::Windows::Forms::Button^  button5;//вправо

	public: System::Windows::Forms::Label^  label2;//счет
	private: System::Windows::Forms::Label^  label3;//сложность
	private: System::Windows::Forms::Button^  button6;//новая игры
	private: System::Windows::Forms::Button^  button7;//главное меню


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		///////////////////////////////////////////////////////////ИНИЦИАЛИЗАЦИЯ КОМПОНЕНТОВ////////////////////////
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Name = L"label1";
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// textBox1
			// 
			resources->ApplyResources(this->textBox1, L"textBox1");
			this->textBox1->Name = L"textBox1";
			// 
			// button2
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			resources->ApplyResources(this->button3, L"button3");
			this->button3->Name = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			resources->ApplyResources(this->button4, L"button4");
			this->button4->Name = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			resources->ApplyResources(this->button5, L"button5");
			this->button5->Name = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// button6
			// 
			resources->ApplyResources(this->button6, L"button6");
			this->button6->Name = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			resources->ApplyResources(this->button7, L"button7");
			this->button7->Name = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

////////////////////////////////////////////////////////////// КАРТА 
#pragma endregion
	void ShowMap()
	{
		label1->Text = "";//убираем старую карту
		for (int i = 0; i < 24; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				if (map[i][j] == '+') label1->Text += "+";else
				if (map[i][j] == '#') label1->Text += "#";else
				if (map[i][j] == '|') label1->Text += "|";else
				if (map[i][j] == ' ') label1->Text += " ";else
				if (map[i][j] == 'G') label1->Text += "G";else
				if (map[i][j] == 'H') label1->Text += "H";else 
				if (map[i][j] == '.') label1->Text += ".";else label1->Text += "?";
			}
			label1->Text += "\n";
		}
	}
	////////////////////////////////////////ОЧИСТКА КАРТЫ/////////////
	void ClearMap()
	{
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 21; j++) {
				if (map[i][j] != '+') 
				if (map[i][j] != '#')
				if (map[i][j] != '|') 
				if (map[i][j] != ' ') map[i][j] = ' ';
			}
		}
	}
	int x;//координата героя
	int y; //координата героя
	int old_x; //старые координаты
	int old_y; // старые координаты 
	int speedmod = 3;//уровень сложности
	int ex;//координата призрака
	int ey;//координата призрака
	int frame;
	int pts;//счет
	bool running;
	bool check = false;

	/////////////////////////////////////////ПОВТОР////////////////////
	void retn()
	{
		running = false;
		x = 16; y = 15; ex = 1; ey = 1;// начальные координаты 
		frame = 0; pts = 0; 
		ClearMap();
		walk_queue.clear();
		BFSArray.clear();
		FindPath(ex, ey, x, y);
		map[ey][ex] = 'G'; // призрак
		map[y][x] = 'H';   // пак ман 
		ShowMap();
		map[ey][ex] = ' ';
		map[y][x] = ' ';
		
		button2->Enabled = true; button3->Enabled = true; 
		button5->Enabled = true; button4->Enabled = true;
		label3->Visible = false; button1->Visible = false;
		label4->Visible = false; textBox1->Visible = false;
		running = true;
		copa();
	}
	//////////////////////////////////////////////////////////Выбор уровня сложности////////////////////////
	void dif()
	{
		String ^diffi = textBox1->Text;
		if (diffi->Length != 1
			|| (wchar_t::ToLower(diffi[0]) != L'n' && wchar_t::ToLower(diffi[0]) != L'т'  //Нормаьный
			&& wchar_t::ToLower(diffi[0]) != L'h' && wchar_t::ToLower(diffi[0]) != L'р'   //Тяжелый
			&& wchar_t::ToLower(diffi[0]) != L'e' && wchar_t::ToLower(diffi[0]) != L'у')) //Легкий 
		{
			MessageBox::Show(L"Введите правильно уровень сложности."); //Если ввели не существующий уровень сложности 
		}
		else
		{
			check = true;
			speedmod = 3;
			if (diffi[0] == 'N') 
			{
				speedmod = 2;
			}
			else if (diffi[0] == 'H')
			{
				speedmod = 1;
			}
		}
	}
	///////////////////////////////////////////////////Управление/////////////////////////
	void copa()
	{
		FindPath(ex, ey, x, y);// поиск игрока 
		while (running) {
			old_x = x;
			old_y = y;
			if (GetAsyncKeyState(VK_UP)) {
				if (map[y - 1][x] == '.') { y--; pts++; }
				else
					if (map[y - 1][x] == ' ') y--;
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				if (map[y + 1][x] == '.') { y++; pts++; }
				else
					if (map[y + 1][x] == ' ') y++;
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				if (map[y][x - 1] == '.') { x--; pts++; }
				else
					if (map[y][x - 1] == ' ') x--;
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				if (map[y][x + 1] == '.') { x++; pts++; }
				else
					if (map[y][x + 1] == ' ') x++;
			}
			if (GetAsyncKeyState(VK_ESCAPE)) {  
				if (MessageBox::Show(this, L"Вы хотите выйти из игры?", L"Подтвердите действие", MessageBoxButtons::YesNo, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1) == System::Windows::Forms::DialogResult::Yes) 
				{
					Application::Exit();
				}
			}
			if (GetAsyncKeyState(0x52)) { // (кнопка R) начать заново 
				retn(); 
				return; 
			}
			if (old_x != x || old_y != y) //условие очереди если сдвинулся. нет то очередь та же
			{
				FindPath(ex, ey, x, y);
			}
			map[y][x] = 'H';

			map[ey][ex] = '.';
			if (frame%speedmod == 0 && walk_queue.size() != 0) // замедление для легкого уровня 3=1
			{
				ex = walk_queue.back().x;
				ey = walk_queue.back().y;
				walk_queue.pop_back();
			}

			map[ey][ex] = 'G';
			label2->Text = L"Ваш счет: " + Convert::ToString(pts);
			if (ex == x && ey == y) {
				break;
			}
			frame++;
			if (!running) break; else ShowMap();
			map[y][x] = ' ';
			Sleep(100);
			Application::DoEvents();
		}//блокировка кнопок( управления) если умер.
		button2->Enabled = FALSE; button3->Enabled = FALSE; button5->Enabled = FALSE; button4->Enabled = FALSE;
		if (running) label1->Text = label2->Text;
		label2->Text = "";
	}
	///////////////////////////////////////////////ОБРАБОТКА ФОРМ///////////////////////
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		dif();
		if (check) {
			button2->Enabled = TRUE; button3->Enabled = TRUE; button5->Enabled = TRUE; button4->Enabled = TRUE;
			button1->Visible = FALSE; button2->Visible = TRUE; button3->Visible = TRUE; button5->Visible = TRUE; button4->Visible = TRUE; button6->Visible = TRUE; button7->Visible = TRUE;
			retn();
		}
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) // ВПРАВО 
	{
		old_x = x;
		old_y = y;
		if (map[y][x + 1] == '.') //проверка скушал ли я точкку и сразу ограничение воизбежания выхода за карту 

		{ 
			x++; pts++;
		}
		else
			if (map[y][x + 1] == ' ') 
			{
				x++;
			}
		if (old_x != x || old_y != y)
			FindPath(ex, ey, x, y);
		label2->Text = L"Ваш счет: " + Convert::ToString(pts);
		map[y][x] = 'H';
		ShowMap();
		map[y][x] = ' ';		
		if (ex == x && ey == y) {
			button2->Enabled = FALSE; button3->Enabled = FALSE; button5->Enabled = FALSE; button4->Enabled = FALSE;
			label1->Text = label2->Text;
			label2->Text = "";
		}
		
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) //ВЛЕВО
	{
		old_x = x;
		old_y = y;
		if (map[y][x - 1] == '.') 
		{
			x--; pts++;
		}
		else
			if (map[y][x - 1] == ' ') 
			{
				x--;
			}		
		if (old_x != x || old_y != y)
		FindPath(ex, ey, x, y);
		label2->Text = L"Ваш счет: " + Convert::ToString(pts);
		map[y][x] = 'H';
		ShowMap();
		map[y][x] = ' ';
			if (ex == x && ey == y) {
			button2->Enabled = FALSE; button3->Enabled = FALSE; button5->Enabled = FALSE; button4->Enabled = FALSE;
			label1->Text = label2->Text;
			label2->Text = "";
		}
			
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) //вверх
	{
		old_x = x;
		old_y = y;
		if (map[y - 1][x] == '.') {
			y--; pts++;
		}
		else
			if (map[y - 1][x] == ' ') {
				y--;
			}
		if (old_x != x || old_y != y)
		FindPath(ex, ey, x, y);
		label2->Text = L"Ваш счет: " + Convert::ToString(pts);
		map[y][x] = 'H';
		ShowMap();
		map[y][x] = ' ';		
		if (ex == x && ey == y) {
			button2->Enabled = FALSE; button3->Enabled = FALSE; button5->Enabled = FALSE; button4->Enabled = FALSE;
			label1->Text = label2->Text;
			label2->Text = "";
		}
		
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) //вниз
	{
		old_x = x;
		old_y = y;
		if (map[y + 1][x] == '.') 
		{
			y++; pts++;
		}
		else
			if (map[y + 1][x] == ' ')
			{
				y++;
			}
		if (old_x != x || old_y != y)
		FindPath(ex, ey, x, y);
		label2->Text = L"Ваш счет: " + Convert::ToString(pts);
		map[y][x] = 'H';
		ShowMap();
		map[y][x] = ' ';		
		if (ex == x && ey == y) {
			button2->Enabled = FALSE; button3->Enabled = FALSE; button5->Enabled = FALSE; button4->Enabled = FALSE;
			label1->Text = label2->Text;
			label2->Text = "";
		}
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//обработчик кнопки начать заново
		retn();
		return;
	}

	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//Обработчик кнопок в главном меню
		running = false;
		check = false;
		label1->Text = "";
		label4->Visible = true; 
		label3->Visible = true;
		textBox1->Visible = true;
		button1->Visible = true;
		button2->Visible = false; 
		button3->Visible = false; 
		button5->Visible = false; 
		button4->Visible = false; 
		button6->Visible = false; 
		button7->Visible = false;
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
		

}
