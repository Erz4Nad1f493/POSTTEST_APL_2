#include <iostream>
#include <limits>

using namespace std;

const int MAX_CLUBS = 100;
const int MAX_PLAYERS_PER_CLUB = 100;

struct Player
{
    string playerName;
};

struct Club
{
    string clubName;
    Player players[MAX_PLAYERS_PER_CLUB];
    int playerCount;
};

bool login()
{
    string nama, pass;
    int Login = 0;
    bool loginBerhasil = false;

    while (Login < 3)
    {
        cout << "-Silahkan masukkan username dan password-" << endl;
        cout << "Username: ";
        getline(cin, nama);
        cout << "Password: ";
        getline(cin, pass);

        if (nama == "ersa nadifa" && pass == "2309106093")
        {
            loginBerhasil = true;
            break;
        }
        else
        {
            cout << "Data yang di berikan salah, coba lagi" << endl;
            Login++;
        }
    }

    if (!loginBerhasil)
    {
        cout << "Anda memasukkan data yang salah 3 kali, program dihentikan" << endl;
        return false;
    }

    return true;
}

void addClub(Club clubs[], int &clubCount)
{
    if (clubCount < MAX_CLUBS)
    {
        Club newClub;
        cout << "Masukkan nama club: ";
        getline(cin, newClub.clubName);
        newClub.playerCount = 0;
        clubs[clubCount] = newClub;
        clubCount++;
        cout << "Club '" << newClub.clubName << "' berhasil ditambahkan." << endl;
    }
    else
    {
        cout << "Jumlah klub sudah mencapai batas maksimum." << endl;
    }
}

void addPlayer(Club clubs[], int clubCount)
{
    string clubName;
    cout << "Masukkan nama club: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < clubCount; ++i)
    {
        if (clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        if (clubs[clubIndex].playerCount < MAX_PLAYERS_PER_CLUB)
        {
            Player newPlayer;
            cout << "Masukkan nama pemain: ";
            getline(cin, newPlayer.playerName);
            clubs[clubIndex].players[clubs[clubIndex].playerCount] = newPlayer;
            clubs[clubIndex].playerCount++;
            cout << "Pemain '" << newPlayer.playerName << "' berhasil ditambahkan ke dalam club '" << clubName << "'." << endl;
        }
        else
        {
            cout << "Jumlah pemain dalam klub '" << clubName << "' sudah mencapai batas maksimum." << endl;
        }
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan list club dan pemain
void displayClubs(const Club clubs[], int clubCount)
{
    cout << "List Club dan Pemain:" << endl;
    for (int i = 0; i < clubCount; ++i)
    {
        cout << "Club: " << clubs[i].clubName << endl;

        if (clubs[i].playerCount > 0)
        {
            cout << "Pemain:" << endl;
            for (int j = 0; j < clubs[i].playerCount; ++j)
            {
                cout << "- " << clubs[i].players[j].playerName << endl;
            }
        }
        else
        {
            cout << "Tidak ada pemain." << endl;
        }

        cout << endl;
    }
}

void editClub(Club clubs[], int clubCount)
{
    string clubName;
    cout << "Masukkan nama club yang akan diubah: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < clubCount; ++i)
    {
        if (clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        cout << "Masukkan nama baru untuk club '" << clubName << "': ";
        getline(cin, clubs[clubIndex].clubName);
        cout << "Club '" << clubName << "' berhasil diubah menjadi '" << clubs[clubIndex].clubName << "'." << endl;
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void editPlayer(Club clubs[], int clubCount)
{
    string clubName, playerName;
    cout << "Masukkan nama club: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < clubCount; ++i)
    {
        if (clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        cout << "Masukkan nama pemain yang akan diubah: ";
        getline(cin, playerName);

        int playerIndex = -1;
        for (int i = 0; i < clubs[clubIndex].playerCount; ++i)
        {
            if (clubs[clubIndex].players[i].playerName == playerName)
            {
                playerIndex = i;
                break;
            }
        }

        if (playerIndex != -1)
        {
            cout << "Masukkan nama baru untuk pemain '" << playerName << "': ";
            getline(cin, clubs[clubIndex].players[playerIndex].playerName);
            cout << "Pemain '" << playerName << "' dalam club '" << clubName << "' berhasil diubah menjadi '" << clubs[clubIndex].players[playerIndex].playerName << "'." << endl;
        }
        else
        {
            cout << "Pemain dengan nama '" << playerName << "' tidak ditemukan dalam club '" << clubName << "'." << endl;
        }
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void deleteClub(Club clubs[], int &clubCount)
{
    string clubName;
    cout << "Masukkan nama club yang akan dihapus: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < clubCount; ++i)
    {
        if (clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        for (int i = clubIndex; i < clubCount - 1; ++i)
        {
            clubs[i] = clubs[i + 1];
        }
        clubCount--;
        cout << "Club '" << clubName << "' berhasil dihapus." << endl;
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void deletePlayer(Club clubs[], int clubCount)
{
    string clubName, playerName;
    cout << "Masukkan nama club: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < clubCount; ++i)
    {
        if (clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        cout << "Masukkan nama pemain yang akan dihapus: ";
        getline(cin, playerName);

        int playerIndex = -1;
        for (int i = 0; i < clubs[clubIndex].playerCount; ++i)
        {
            if (clubs[clubIndex].players[i].playerName == playerName)
            {
                playerIndex = i;
                break;
            }
        }

        if (playerIndex != -1)
        {
            for (int i = playerIndex; i < clubs[clubIndex].playerCount - 1; ++i)
            {
                clubs[clubIndex].players[i] = clubs[clubIndex].players[i + 1];
            }
            clubs[clubIndex].playerCount--;
            cout << "Pemain '" << playerName << "' dalam club '" << clubName << "' berhasil dihapus." << endl;
        }
        else
        {
            cout << "Pemain dengan nama '" << playerName << "' tidak ditemukan dalam club '" << clubName << "'." << endl;
        }
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

int main()
{
    if (!login())
    {
        return 0;
    }

    Club clubs[MAX_CLUBS];
    int clubCount = 0;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Tambah Club" << endl;
        cout << "2. Tambah Pemain ke Club" << endl;
        cout << "3. Tampilkan List Club dan Pemain" << endl;
        cout << "4. Edit Nama Club" << endl;
        cout << "5. Edit Nama Pemain" << endl;
        cout << "6. Hapus Club" << endl;
        cout << "7. Hapus Pemain dari Club" << endl;
        cout << "0. Keluar" << endl;

        int choice;
        cout << "Pilihan Anda: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan newline karakter dari buffer

        switch (choice)
        {
        case 1:
            addClub(clubs, clubCount);
            break;
        case 2:
            addPlayer(clubs, clubCount);
            break;
        case 3:
            displayClubs(clubs, clubCount);
            break;
        case 4:
            editClub(clubs, clubCount);
            break;
        case 5:
            editPlayer(clubs, clubCount);
            break;
        case 6:
            deleteClub(clubs, clubCount);
            break;
        case 7:
            deletePlayer(clubs, clubCount);
            break;
        case 0:
            cout << "Program selesai." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
