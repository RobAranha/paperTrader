#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>

namespace paperTrader {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Paper trading application, with data being refreshed through external python script
	/// </summary>
	public ref class tradingInterface : public System::Windows::Forms::Form
	{
	public:
		// Initalize form and load data from txt file
		tradingInterface(void)
		{
			InitializeComponent();
			loadData();
		}

	protected:
		/// Clean up any resources being used.
		~tradingInterface()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ticker;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Market_Value;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Avg_Price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Shares;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PL;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Quantity;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Buy;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Sell;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Ticker = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Market_Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Avg_Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Shares = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PL = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantity = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Buy = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Sell = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 4);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Paper Trader";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 86);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Portfolio Balance:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 119);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Porfolio Book Value:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 151);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Profit/(Loss)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 264);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Funds Available:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 292);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(176, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Add/(Widthdraw) Funds";
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Default;
			this->button1->Location = System::Drawing::Point(81, 329);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 35);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Request Funds";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &tradingInterface::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(236, 289);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(78, 26);
			this->textBox1->TabIndex = 7;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &tradingInterface::textBox1_KeyDown);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(231, 86);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 20);
			this->label7->TabIndex = 8;
			this->label7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(231, 119);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 20);
			this->label8->TabIndex = 9;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(231, 151);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(18, 20);
			this->label9->TabIndex = 10;
			this->label9->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(231, 264);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(18, 20);
			this->label10->TabIndex = 11;
			this->label10->Text = L"0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(671, 21);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(132, 29);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Watch List";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Ticker,
					this->Market_Value, this->Avg_Price, this->Shares, this->PL, this->Quantity, this->Buy, this->Sell
			});
			this->dataGridView1->Location = System::Drawing::Point(338, 53);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(789, 311);
			this->dataGridView1->TabIndex = 19;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &tradingInterface::dataGridView1_CellContentClick);
			// 
			// Ticker
			// 
			this->Ticker->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Ticker->HeaderText = L"Ticker";
			this->Ticker->MinimumWidth = 6;
			this->Ticker->Name = L"Ticker";
			this->Ticker->Width = 76;
			// 
			// Market_Value
			// 
			this->Market_Value->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Market_Value->HeaderText = L"Market Value";
			this->Market_Value->MinimumWidth = 6;
			this->Market_Value->Name = L"Market_Value";
			this->Market_Value->Width = 128;
			// 
			// Avg_Price
			// 
			this->Avg_Price->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Avg_Price->HeaderText = L"Avg. Price";
			this->Avg_Price->MinimumWidth = 6;
			this->Avg_Price->Name = L"Avg_Price";
			this->Avg_Price->Width = 104;
			// 
			// Shares
			// 
			this->Shares->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Shares->HeaderText = L"Shares Held";
			this->Shares->MinimumWidth = 6;
			this->Shares->Name = L"Shares";
			this->Shares->Width = 122;
			// 
			// PL
			// 
			this->PL->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->PL->HeaderText = L"Avg. P/L";
			this->PL->MinimumWidth = 6;
			this->PL->Name = L"PL";
			this->PL->Width = 92;
			// 
			// Quantity
			// 
			this->Quantity->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Quantity->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
			this->Quantity->HeaderText = L"Quantity";
			this->Quantity->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"10", L"100", L"1000" });
			this->Quantity->MinimumWidth = 6;
			this->Quantity->Name = L"Quantity";
			this->Quantity->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Quantity->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Quantity->Width = 93;
			// 
			// Buy
			// 
			this->Buy->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Buy->HeaderText = L"Buy";
			this->Buy->MinimumWidth = 6;
			this->Buy->Name = L"Buy";
			this->Buy->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Buy->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Buy->Width = 61;
			// 
			// Sell
			// 
			this->Sell->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Sell->HeaderText = L"Sell";
			this->Sell->MinimumWidth = 6;
			this->Sell->Name = L"Sell";
			this->Sell->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Sell->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Sell->Width = 60;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(606, 372);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 21;
			this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &tradingInterface::textBox2_KeyDown);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Default;
			this->button2->Location = System::Drawing::Point(732, 368);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(152, 35);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Add Ticker";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &tradingInterface::button2_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(13, 394);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 20);
			this->label11->TabIndex = 23;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(13, 394);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(60, 20);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Status:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1019, 368);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 34);
			this->button3->TabIndex = 25;
			this->button3->Text = L"Update";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &tradingInterface::button3_Click);
			// 
			// tradingInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1151, 428);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"tradingInterface";
			this->Text = L"tradingInterface";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &tradingInterface::tradingInterface_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
		// Add or widthdrawl funds
		// Get user input from textbox 1 and add amount to market value, book value, and funds available
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get data from form
		String^ input = textBox1->Text;
		String^ fundsAva = label10->Text;
		String^ mktVal = label7->Text;
		String^ bookVal = label8->Text;

		// Cast input to double
		double inputFunds;
		bool validInput = Double::TryParse(input, inputFunds);
		cout << validInput;

		// If invalid user input then return
		if (validInput == 0 || (inputFunds < 0.01 && inputFunds > 0) || (inputFunds > -0.01 && inputFunds < 0)) {
			label13->Text = "Status: Error - invalid input";
			return;
		}

		// Get portfolio data from form and cast to double
		double funds = Double::Parse(fundsAva);
		double marketValue = Double::Parse(mktVal);
		double bookValue = Double::Parse(bookVal);

		// If over amount of funds available then return
		if (inputFunds < 0 && inputFunds * -1 > funds) {
			label13->Text = "Status: Error - Widthdrwal over limit";
			return;
		}

		// Add funds to portfolio balance, round result to 2 decimals, and cast to system string
		fundsAva = System::Convert::ToString(round((funds + inputFunds) * 100.0) / 100.0);
		mktVal = System::Convert::ToString(round((inputFunds + marketValue) * 100.0) / 100.0);
		bookVal = System::Convert::ToString(round((inputFunds + bookValue) * 100.0) / 100.0);

		// Write output to form
		label10->Text = fundsAva;
		label7->Text = mktVal;
		label8->Text = bookVal;

		// Reset textbox
		textBox1->Text = "";

		// Update Status Message
		label13->Text = "Status: Funds transferred";

		// Save Data
		saveData();
	}


		   // Buy or sell shares
		   // On datagrid click, if column == 6(7) reduce(add) funds by market price multipled by quantity for selected ticker symbol  
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		// Get row and column
		int row = dataGridView1->CurrentCell->RowIndex;
		int col = dataGridView1->CurrentCell->ColumnIndex;

		// Get data from form
		String^ txtMktP = dataGridView1->Rows[row]->Cells[1]->Value->ToString();
		String^ txtAvgP = dataGridView1->Rows[row]->Cells[2]->Value->ToString();
		String^ txtShares = dataGridView1->Rows[row]->Cells[3]->Value->ToString();
		String^ txtPL = dataGridView1->Rows[row]->Cells[4]->Value->ToString();
		String^ txtQuant = dataGridView1->Rows[row]->Cells[5]->Value->ToString();
		String^ fundsAva = label10->Text;

		// Cast values to doubles
		double mktP = Double::Parse(txtMktP);
		double avgP = Double::Parse(txtAvgP);
		double shares = Double::Parse(txtShares);
		double PL = Double::Parse(txtPL);
		double quant = Double::Parse(txtQuant);
		double funds = Double::Parse(fundsAva);

		// Calculations for buying shares
		if (col == 6) {
			if (quant * mktP > funds) {
				label13->Text = "Status: Error - Funds not available";
			}
			else {
				funds = round((funds - quant * mktP) * 100.0) / 100.0;
				avgP = round(((avgP * shares + mktP * quant) / (shares + quant)) * 100000.0) / 100000.0;	//Round to 5 decimals;

				shares = shares + quant;
				PL = round((mktP - avgP) * 100000.0) / 100000.0;											//Round to 5 decimals;
				label13->Text = "Status: Shares bought successfully";
			}
			// Calculations for selling shares
		}
		else if (col == 7) {
			if (quant > shares) {
				label13->Text = "Status: Error - Not enough shares";
			}
			else {
				funds = round((funds + quant * mktP) * 100.0) / 100.0;
				shares = shares - quant;
				if (shares == 0) {
					avgP = 0;
					PL = 0;
				}
				label13->Text = "Status: Shares sold successfully";
			}
		}

		// Convert variables back to system strings and write to form
		label10->Text = System::Convert::ToString(funds);
		dataGridView1->Rows[row]->Cells[2]->Value = System::Convert::ToString(avgP);
		dataGridView1->Rows[row]->Cells[3]->Value = System::Convert::ToString(shares);
		dataGridView1->Rows[row]->Cells[4]->Value = System::Convert::ToString(PL);

		// Save data
		saveData();
	}


		   // Add ticker symbol to datagrid
		   // Get user input from textBox2 and add symbol to datagrid
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		// Get user input from textBox2 and cast to string
		String^ input = textBox2->Text;
		string txtInput = msclr::interop::marshal_as<string>(input);

		// Case for adding first row
		if (dataGridView1->Rows->Count == 0) {
			dataGridView1->Rows->Add(input, "0", "0", "0", "0", "1");
			label13->Text = "Status: Ticker successfully added";
		}
		else {
			// Else check if ticker is already in dataGrid, add if not
			for (int i = 0; i < dataGridView1->Rows->Count; i++) {
				string curVal = msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
				// If the ticker is already in the list then return
				if (txtInput.compare(curVal) == 0) {
					label13->Text = "Status: Error - Ticker already in list";
					return;
				}
				// If ticker not found, add new symbol
				if (i == dataGridView1->Rows->Count - 1 && txtInput != "") {
					dataGridView1->Rows->Add(input, "0", "0", "0", "0", "1");
					label13->Text = "Status: Ticker successfully added";
					textBox2->Text = "";
					break;																	//break to stop avoid looping over new row
				}
			}
		}

		// Save data with new stock ticker to include in update
		saveData();

		// Update Ticker List
		update();

		// Save data
		saveData();
	}


		   // Bind Enter key for add/widthdrawl funds input box
	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (int(e->KeyCode) == 13) {
			button1->PerformClick();
		}
	}


		   // Bind Enter key for add ticker input box
	private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (int(e->KeyCode) == 13) {
			button2->PerformClick();
		}
	}


		   // Force update
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		update();
		saveData();
		label13->Text = "Status: Update Successful";
	}


		   // Force save on close
	private: System::Void tradingInterface_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		saveData();
	}


		   // Update market values for all tickers in the datagrid
	private: System::Void update() {

		string** dataList;
		string sym;
		string price;
		string ticker;

		String^ txtMktPrice = "0";
		String^ txtAvgPL;
		String^ txtAvgPrice;
		String^ txtBookVal;
		String^ txtMktVal;
		String^ txtPL;
		String^ txtShares;

		double avgPrice;
		double mktPrice;
		double avgPL;
		double mktVal;
		double bookVal;
		double PL;
		double shares;
		int count;

		// Save data to update tickerList for api pull
		saveData();

		txtMktVal = label7->Text;
		txtBookVal = label8->Text;
		count = dataGridView1->Rows->Count;

		// Call python script to fetch stock data, storing result in data.txt
		int result = system("GetData.py");

		// Resize 2D dynamic Array
		dataList = new string * [count];
		for (int i = 0; i < count; ++i) {
			dataList[i] = new string[2]; //2 columns
		}

		// Read in data
		ifstream file("data.txt");

		// Add symbols and market prices from file to dataList
		int rows = 0;
		while (file >> sym >> price) {
			dataList[rows][0] = sym;
			dataList[rows][1] = price;
			rows++;
		}
		file.close();

		// Get book value for PL and updated market value calculation
		bookVal = Double::Parse(txtBookVal);
		mktVal = bookVal;

		// Loop through each row in data grid, find assosiated price values, and update grid
		for (int i = 0; i < dataGridView1->Rows->Count; i++) {
			// Get grid information
			ticker = msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
			txtAvgPrice = dataGridView1->Rows[i]->Cells[2]->Value->ToString();
			txtShares = dataGridView1->Rows[i]->Cells[3]->Value->ToString();

			// Get assosiated price from data array and update data grid
			for (int m = 0; m < count; m++) {
				if (ticker._Equal(dataList[m][0])) {
					txtMktPrice = gcnew String(dataList[m][1].c_str());

					// Cast values to double for calulations
					avgPrice = Double::Parse(txtAvgPrice);
					mktPrice = Double::Parse(txtMktPrice);
					shares = Double::Parse(txtShares);

					// Calculate average PL
					if (shares == 0) {
						avgPL = 0;
					}
					else {
						avgPL = round((mktPrice - avgPrice) * 100000.0) / 100000.0;					//Round to 5 decimals
					}

					// Update portoflio market value and PL
					mktVal = round((mktVal + avgPL * shares) * 100.0) / 100.0;
					PL = round((mktVal - bookVal) * 100.0) / 100.0;

					// Cast values to system string
					txtAvgPL = System::Convert::ToString(avgPL);
					txtMktVal = System::Convert::ToString(mktVal);
					txtPL = System::Convert::ToString(PL);

					// Write values to form
					dataGridView1->Rows[i]->Cells[1]->Value = txtMktPrice;
					dataGridView1->Rows[i]->Cells[4]->Value = txtAvgPL;
					label7->Text = txtMktVal;
					label9->Text = txtPL;
					break;
				}
			}
		}

		// Free data array and ticker list
		for (int i = 0; i < count; i++) {
			delete[] dataList[i];
		}
		delete[] dataList;
		dataList = NULL;

		// Save data
		saveData();
	}


		   // On open, load data from SaveData file
		   // Update portfolio variables and datagrid
	private: System::Void loadData() {

		ifstream file("SaveData.txt");
		string ticker;
		string mktVal;
		string avgP;
		string shares;
		string avgPL;

		// Read in data from python file and update form
		// Use mktVal as temp to store data for portfolio balances (header information)
		while (file >> ticker >> mktVal >> avgP >> shares >> avgPL) {
			if (ticker == "portBal") {
				label7->Text = gcnew String(mktVal.c_str());
			}
			else if (ticker == "bookVal") {
				label8->Text = gcnew String(mktVal.c_str());
			}
			else if (ticker == "PL") {
				label9->Text = gcnew String(mktVal.c_str());
			}
			else if (ticker == "funds") {
				label10->Text = gcnew String(mktVal.c_str());
			}
			// Convert all data to system strings and add row to datagrid
			else {
				dataGridView1->Rows->Add(gcnew String(ticker.c_str()), gcnew String(mktVal.c_str()), gcnew String(avgP.c_str()),
					gcnew String(shares.c_str()), gcnew String(avgPL.c_str()), "1");
			}
		}

		file.close();
		label13->Text = "Status: Load Successful";
	}


		   // Save all data in the form to SaveData.txt
	private: System::Void saveData() {
		ofstream file("SaveData.txt");
		string ticker;
		string mktVal;
		string avgP;
		string shares;
		string avgPL;

		// Add data from file to new array
		// Use mktVal as temp to store data for portfolio balances (header information)
		file << "portBal " << double::Parse(label7->Text) << " - - -" << "\n";
		file << "bookVal " << double::Parse(label8->Text) << " - - -" << "\n";
		file << "PL " << double::Parse(label9->Text) << " - - -" << "\n";
		file << "funds " << double::Parse(label10->Text) << " - - -" << "\n";

		// Store data grid information
		for (int i = 0; i < dataGridView1->Rows->Count; i++) {
			ticker = msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
			mktVal = msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[1]->Value->ToString());
			avgP = msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[2]->Value->ToString());
			shares = msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[3]->Value->ToString());
			avgPL = msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[4]->Value->ToString());
			file << ticker << " " << mktVal << " " << avgP << " " << shares << " " << avgPL << "\n";
		}
		file.close();

	}

	};
}
