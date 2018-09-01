#pragma once

namespace WAR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для WARForm
	/// </summary>
	public ref class WARForm : public System::Windows::Forms::Form
	{
	public:
		LOGIC_WAR LOGIC;
		WARForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WARForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  start;
	private: System::Windows::Forms::Label^  infantry;
	private: System::Windows::Forms::Label^  cavalry;
	private: System::Windows::Forms::Label^  tanks;
	private: System::Windows::Forms::Label^  planes;
	private: System::Windows::Forms::Label^  infantry_count;
	private: System::Windows::Forms::Label^  cavalry_count;
	private: System::Windows::Forms::Label^  tanks_count;
	private: System::Windows::Forms::Label^  planes_count;
	private: System::Windows::Forms::Button^  button_infantry;
	private: System::Windows::Forms::Button^  button_cavalry;
	private: System::Windows::Forms::Button^  button_tanks;
	private: System::Windows::Forms::Button^  button_planes;
	private: System::Windows::Forms::Label^  current_player;
	private: System::Windows::Forms::Button^  current_player_check;
	private: System::Windows::Forms::PictureBox^  playing_field;
	private: System::Windows::Forms::Label^  amount_bot_text;
	private: System::Windows::Forms::NumericUpDown^  enter_amount_bots;
	private: System::Windows::Forms::Panel^  cover;
	private: System::Windows::Forms::Label^  cover_text;




	protected:

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
		void InitializeComponent(void)
		{
			this->start = (gcnew System::Windows::Forms::Button());
			this->infantry = (gcnew System::Windows::Forms::Label());
			this->cavalry = (gcnew System::Windows::Forms::Label());
			this->tanks = (gcnew System::Windows::Forms::Label());
			this->planes = (gcnew System::Windows::Forms::Label());
			this->infantry_count = (gcnew System::Windows::Forms::Label());
			this->cavalry_count = (gcnew System::Windows::Forms::Label());
			this->tanks_count = (gcnew System::Windows::Forms::Label());
			this->planes_count = (gcnew System::Windows::Forms::Label());
			this->button_infantry = (gcnew System::Windows::Forms::Button());
			this->button_cavalry = (gcnew System::Windows::Forms::Button());
			this->button_tanks = (gcnew System::Windows::Forms::Button());
			this->button_planes = (gcnew System::Windows::Forms::Button());
			this->current_player = (gcnew System::Windows::Forms::Label());
			this->current_player_check = (gcnew System::Windows::Forms::Button());
			this->playing_field = (gcnew System::Windows::Forms::PictureBox());
			this->amount_bot_text = (gcnew System::Windows::Forms::Label());
			this->enter_amount_bots = (gcnew System::Windows::Forms::NumericUpDown());
			this->cover = (gcnew System::Windows::Forms::Panel());
			this->cover_text = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playing_field))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enter_amount_bots))->BeginInit();
			this->cover->SuspendLayout();
			this->SuspendLayout();
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(659, 30);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(145, 57);
			this->start->TabIndex = 0;
			this->start->Text = L"Start";
			this->start->UseCompatibleTextRendering = true;
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &WARForm::start_game);
			// 
			// infantry
			// 
			this->infantry->AutoSize = true;
			this->infantry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infantry->Location = System::Drawing::Point(691, 129);
			this->infantry->Name = L"infantry";
			this->infantry->Size = System::Drawing::Size(43, 13);
			this->infantry->TabIndex = 1;
			this->infantry->Text = L"Пехота";
			// 
			// cavalry
			// 
			this->cavalry->AutoSize = true;
			this->cavalry->Location = System::Drawing::Point(691, 161);
			this->cavalry->Name = L"cavalry";
			this->cavalry->Size = System::Drawing::Size(62, 13);
			this->cavalry->TabIndex = 1;
			this->cavalry->Text = L"Кавалерия";
			// 
			// tanks
			// 
			this->tanks->AutoSize = true;
			this->tanks->Location = System::Drawing::Point(691, 193);
			this->tanks->Name = L"tanks";
			this->tanks->Size = System::Drawing::Size(38, 13);
			this->tanks->TabIndex = 1;
			this->tanks->Text = L"Танки";
			// 
			// planes
			// 
			this->planes->AutoSize = true;
			this->planes->Location = System::Drawing::Point(691, 225);
			this->planes->Name = L"planes";
			this->planes->Size = System::Drawing::Size(59, 13);
			this->planes->TabIndex = 1;
			this->planes->Text = L"Самолеты";
			// 
			// infantry_count
			// 
			this->infantry_count->AutoSize = true;
			this->infantry_count->Location = System::Drawing::Point(791, 129);
			this->infantry_count->Name = L"infantry_count";
			this->infantry_count->Size = System::Drawing::Size(13, 13);
			this->infantry_count->TabIndex = 1;
			this->infantry_count->Text = L"0";
			// 
			// cavalry_count
			// 
			this->cavalry_count->AutoSize = true;
			this->cavalry_count->Location = System::Drawing::Point(791, 161);
			this->cavalry_count->Name = L"cavalry_count";
			this->cavalry_count->Size = System::Drawing::Size(13, 13);
			this->cavalry_count->TabIndex = 1;
			this->cavalry_count->Text = L"0";
			// 
			// tanks_count
			// 
			this->tanks_count->AutoSize = true;
			this->tanks_count->Location = System::Drawing::Point(791, 193);
			this->tanks_count->Name = L"tanks_count";
			this->tanks_count->Size = System::Drawing::Size(13, 13);
			this->tanks_count->TabIndex = 1;
			this->tanks_count->Text = L"0";
			// 
			// planes_count
			// 
			this->planes_count->AutoSize = true;
			this->planes_count->Location = System::Drawing::Point(791, 225);
			this->planes_count->Name = L"planes_count";
			this->planes_count->Size = System::Drawing::Size(13, 13);
			this->planes_count->TabIndex = 1;
			this->planes_count->Text = L"0";
			// 
			// button_infantry
			// 
			this->button_infantry->Location = System::Drawing::Point(659, 122);
			this->button_infantry->Name = L"button_infantry";
			this->button_infantry->Size = System::Drawing::Size(26, 26);
			this->button_infantry->TabIndex = 2;
			this->button_infantry->Text = L"П";
			this->button_infantry->UseVisualStyleBackColor = true;
			this->button_infantry->Click += gcnew System::EventHandler(this, &WARForm::button_infantry_Click);
			// 
			// button_cavalry
			// 
			this->button_cavalry->Location = System::Drawing::Point(659, 154);
			this->button_cavalry->Name = L"button_cavalry";
			this->button_cavalry->Size = System::Drawing::Size(26, 26);
			this->button_cavalry->TabIndex = 2;
			this->button_cavalry->Text = L"К";
			this->button_cavalry->UseVisualStyleBackColor = true;
			this->button_cavalry->Click += gcnew System::EventHandler(this, &WARForm::button_cavalry_Click);
			// 
			// button_tanks
			// 
			this->button_tanks->Location = System::Drawing::Point(659, 186);
			this->button_tanks->Name = L"button_tanks";
			this->button_tanks->Size = System::Drawing::Size(26, 26);
			this->button_tanks->TabIndex = 2;
			this->button_tanks->Text = L"Т";
			this->button_tanks->UseVisualStyleBackColor = true;
			this->button_tanks->Click += gcnew System::EventHandler(this, &WARForm::button_tanks_Click);
			// 
			// button_planes
			// 
			this->button_planes->Location = System::Drawing::Point(659, 218);
			this->button_planes->Name = L"button_planes";
			this->button_planes->Size = System::Drawing::Size(26, 26);
			this->button_planes->TabIndex = 2;
			this->button_planes->Text = L"С";
			this->button_planes->UseVisualStyleBackColor = true;
			this->button_planes->Click += gcnew System::EventHandler(this, &WARForm::button_planes_Click);
			// 
			// current_player
			// 
			this->current_player->AutoSize = true;
			this->current_player->Location = System::Drawing::Point(656, 267);
			this->current_player->Name = L"current_player";
			this->current_player->Size = System::Drawing::Size(67, 13);
			this->current_player->TabIndex = 3;
			this->current_player->Text = L"Ход игрока:";
			// 
			// current_player_check
			// 
			this->current_player_check->BackColor = System::Drawing::Color::Red;
			this->current_player_check->Location = System::Drawing::Point(778, 260);
			this->current_player_check->Name = L"current_player_check";
			this->current_player_check->Size = System::Drawing::Size(26, 26);
			this->current_player_check->TabIndex = 2;
			this->current_player_check->UseVisualStyleBackColor = false;
			// 
			// playing_field
			// 
			this->playing_field->Location = System::Drawing::Point(30, 30);
			this->playing_field->Name = L"playing_field";
			this->playing_field->Size = System::Drawing::Size(601, 601);
			this->playing_field->TabIndex = 4;
			this->playing_field->TabStop = false;
			this->playing_field->Click += gcnew System::EventHandler(this, &WARForm::game_field_click);
			this->playing_field->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &WARForm::paintFiled);
			// 
			// amount_bot_text
			// 
			this->amount_bot_text->AutoSize = true;
			this->amount_bot_text->Location = System::Drawing::Point(656, 314);
			this->amount_bot_text->Name = L"amount_bot_text";
			this->amount_bot_text->Size = System::Drawing::Size(104, 13);
			this->amount_bot_text->TabIndex = 5;
			this->amount_bot_text->Text = L"Количество ботов: ";
			// 
			// enter_amount_bots
			// 
			this->enter_amount_bots->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->enter_amount_bots->Location = System::Drawing::Point(768, 311);
			this->enter_amount_bots->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->enter_amount_bots->Name = L"enter_amount_bots";
			this->enter_amount_bots->Size = System::Drawing::Size(36, 16);
			this->enter_amount_bots->TabIndex = 6;
			this->enter_amount_bots->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// cover
			// 
			this->cover->BackColor = System::Drawing::Color::White;
			this->cover->Controls->Add(this->cover_text);
			this->cover->Location = System::Drawing::Point(30, 30);
			this->cover->Name = L"cover";
			this->cover->Size = System::Drawing::Size(601, 601);
			this->cover->TabIndex = 7;
			// 
			// cover_text
			// 
			this->cover_text->AutoSize = true;
			this->cover_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cover_text->Location = System::Drawing::Point(211, 285);
			this->cover_text->Name = L"cover_text";
			this->cover_text->Size = System::Drawing::Size(178, 29);
			this->cover_text->TabIndex = 0;
			this->cover_text->Text = L"Нажмите Start";
			// 
			// WARForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(837, 675);
			this->Controls->Add(this->cover);
			this->Controls->Add(this->enter_amount_bots);
			this->Controls->Add(this->amount_bot_text);
			this->Controls->Add(this->playing_field);
			this->Controls->Add(this->current_player);
			this->Controls->Add(this->current_player_check);
			this->Controls->Add(this->button_planes);
			this->Controls->Add(this->button_tanks);
			this->Controls->Add(this->button_cavalry);
			this->Controls->Add(this->button_infantry);
			this->Controls->Add(this->infantry_count);
			this->Controls->Add(this->cavalry_count);
			this->Controls->Add(this->tanks_count);
			this->Controls->Add(this->planes_count);
			this->Controls->Add(this->infantry);
			this->Controls->Add(this->cavalry);
			this->Controls->Add(this->tanks);
			this->Controls->Add(this->planes);
			this->Controls->Add(this->start);
			this->Name = L"WARForm";
			this->Text = L"WARForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playing_field))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enter_amount_bots))->EndInit();
			this->cover->ResumeLayout(false);
			this->cover->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void set_count_label(PLAYER_WAR ^p) {
		infantry_count->Text = Convert::ToString(p->getInfantry());
		cavalry_count->Text = Convert::ToString(p->getCavalry());
		tanks_count->Text = Convert::ToString(p->getTanks());
		planes_count->Text = Convert::ToString(p->getPlanes());
	}
	private: System::Void reset_unit_label() {
		infantry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		cavalry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		tanks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		planes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		if (LOGIC.getCurrentUnit() == INFANTRY)
			this->infantry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		else if (LOGIC.getCurrentUnit() == CAVALRY)
			this->cavalry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		else if (LOGIC.getCurrentUnit() == TANKS)
			this->tanks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		else if (LOGIC.getCurrentUnit() == PLANES)
			this->planes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
	}
	private: System::Void button_infantry_Click(System::Object^  sender, System::EventArgs^  e) {
		LOGIC.changeCurrentUnit(INFANTRY);
		reset_unit_label();
	}
	private: System::Void button_cavalry_Click(System::Object^  sender, System::EventArgs^  e) {
		LOGIC.changeCurrentUnit(CAVALRY);
		reset_unit_label();
	}
	private: System::Void button_tanks_Click(System::Object^  sender, System::EventArgs^  e) {
		LOGIC.changeCurrentUnit(TANKS);
		reset_unit_label();
	}
	private: System::Void button_planes_Click(System::Object^  sender, System::EventArgs^  e) {
		LOGIC.changeCurrentUnit(PLANES);
		reset_unit_label();
	}
	private: System::Void paintFiled(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		LOGIC.getMap()->Draw(e);
		LOGIC.UpdateGraphics(e, current_player_check, current_player, cover, cover_text);
		set_count_label(LOGIC.getPlayers(LOGIC.getCurrentPlayer() - 1));
	}
	private: System::Void start_game(System::Object^  sender, System::EventArgs^  e) {
		cover->Size = System::Drawing::Size(0, 0);
		this->Controls->Remove(cover_text);
		start->Text = "Restart";
		LOGIC.Reset();
		LOGIC.StartGame();
		set_count_label(LOGIC.getPlayers(1));
		LOGIC.setAmountBot(Int32::Parse(enter_amount_bots->Text));
		current_player->Text = "Ход игрока: ";
		playing_field->Invalidate();
	}
	private: System::Void game_field_click(System::Object^  sender, System::EventArgs^  e) {
		Point p = playing_field->PointToClient(System::Windows::Forms::Cursor::Position);
		LOGIC.UpdateGameField(p.X / LOGIC.getMap()->getSizeOfCell(), p.Y / LOGIC.getMap()->getSizeOfCell());
		playing_field->Invalidate();
		reset_unit_label();
	}
	};
}
