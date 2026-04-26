#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class RenderManager {
private:
    const int UI_WIDTH = 60;
    const int TOP_HEIGHT = 15;
    const int BOT_HEIGHT = 6;

    // 커서 위치 이동 함수
    

public:
    void gotoxy(int x, int y) {
        // ANSI 이스케이프 시퀀스 (x, y 좌표는 1부터 시작)
        printf("\033[%d;%dH", y, x);
    }
    // 화면 전체 초기화 및 UI 틀 그리기
    void Initialize() {
        // 1. 화면 전체 지우기
        printf("\033[2J");
        // 2. 커서를 맨 위(1,1)로 이동
        printf("\033[H");

        // --- UI 틀 그리기 (endl 대신 \n 사용으로 속도 최적화) ---
        // 상단 테두리
        cout << "┌";
        for (int i = 0; i < UI_WIDTH; i++) cout << "─";
        cout << "┐\n";

        // 상단 박스 (y=2 ~ y=16)
        for (int i = 0; i < TOP_HEIGHT; i++) {
            cout << "│";
            for (int j = 0; j < UI_WIDTH; j++) cout << " ";
            cout << "│\n";
        }

        // 중간 구분선 (y=17)
        cout << "├";
        for (int i = 0; i < UI_WIDTH; i++) cout << "─";
        cout << "┤\n";

        // 하단 박스 (y=18 ~ y=23)
        for (int i = 0; i < BOT_HEIGHT; i++) {
            cout << "│";
            for (int j = 0; j < UI_WIDTH; j++) cout << " ";
            cout << "│\n";
        }

        // 하단 테두리 (y=24)
        cout << "└";
        for (int i = 0; i < UI_WIDTH; i++) cout << "─";
        cout << "┘" << endl;

        cout.flush(); // 버퍼를 강제로 비워 화면에 즉시 표시
    }

    // 상단 영역(배경/몬스터) 그리기
    void DrawScene(const char* scene) {
        // 1. 상단 박스 내부(y=2~16)를 공백으로 청소
        for (int i = 0; i < TOP_HEIGHT; i++) {
            gotoxy(2,3 + i);
            for (int j = 0; j < UI_WIDTH; j++) cout << " ";
        }

        // 2. 장면 데이터 출력
        stringstream ss(scene);
        string line;
        int currentY = 2; // 상단 박스 내부 시작 위치

        while (getline(ss, line)) {
            if (currentY > 16) break; // 상단 영역 이탈 방지

            gotoxy(2, currentY); // x좌표는 왼쪽 테두리 다음인 2
            cout << line;        // 주의: endl이나 \n을 쓰지 않음
            currentY++;
        }

        // 3. 작업 후 커서를 안전한 곳으로 이동
        gotoxy(3, 19); 
        cout.flush();
    }

    // 하단 영역(로그) 메시지 출력
    void DrawLog(string message) {
        // 로그창의 첫 줄(y=19) 위치로 이동
        gotoxy(2, 19);
        for (int i = 0; i < UI_WIDTH; i++) cout << " "; // 기존 줄 지우기

        gotoxy(3, 19);
        cout << ">> " << message;

        // 입력을 위해 커서를 로그창 안쪽 적절한 위치에 고정
        gotoxy(3, 20);
        cout.flush();
    }
    
    void ClearLog() {
        // BOT_HEIGHT(6)만큼 반복하며 한 줄씩 지웁니다.
        for (int i = 0; i < BOT_HEIGHT; i++) {
            // 하단 박스 시작 위치인 y=18부터 한 줄씩 이동
            gotoxy(2, 18+i);
        
            // UI_WIDTH만큼 공백을 채워 기존 텍스트 제거
            for (int j = 0; j < UI_WIDTH; j++) {
                cout << " ";
            }
        }
    
        // 지운 후 커서를 다시 로그 시작 지점(y=19)으로 되돌려 놓습니다.
        gotoxy(3, 19);
        cout.flush();
    }
};