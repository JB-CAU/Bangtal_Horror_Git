#include <bangtal>

using namespace bangtal;

int main()
{

	auto room1 = Scene::create("룸1", "Images/료칸(방1)_다루마.jpg");
	auto room2 = Scene::create("룸2", "Images/료칸_반전(방2).png");
	// 차를 4번 이상 마시면 정신이 혼미해져서 방2로 이동한다.
	auto room3 = Scene::create("일본도", "Images/일본도.png");
	auto room4 = Scene::create("다과", "Images/웰컴다과.jpg");

	auto daruma_eye = false; 

	// 료칸 방 오른쪽에 벚꽃 화분을 추가한다.
	// 료칸 방 왼쪽에 문을 여닫는 것을 추가한다.

	auto brush = Object::create("Images/붓.png", room1, 500, 180);
	brush->setScale(0.1f);
	brush->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showMessage("부드러운 새의 깃털, 마호가니 나무, 분명 비싼 붓이다.\n 심지 부분은 바짝 말라 있다.");
		brush->pick();
		return 0;
		});

	auto exit = Object::create("Images/화살표.png", room3, 470, 30);
	exit->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room1->enter();
		return 0;
		});

	auto click_object = Object::create("Images/투명배경.png", room1, 445, 250);
	click_object->setScale(0.3f);
	click_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room3->enter();
		showMessage("화려하게 장식된 검이다. \n 매끈하고 예리하게 다듬어져 있다.");
		return 0;
		});

	auto pillow = Object::create("Images/다홍색_방석.png", room1, 780, 210);
	pillow->setScale(0.2f);
	pillow->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showMessage("이질적으로 생겼지만 푹신한....\n 어라, 딱딱한 무언가가 만져진다. \n 어딘가 쓸모가 있을지도?");
		pillow->pick();
		return 0;
		});
	// 방석을 일본도에 가져다대면 찢어지고, 거기서 잉크를 얻는 코드 추가

	auto daruma = Object::create("Images/다루마_눈없음.png", room1, 810, 340);
	daruma->setScale(0.1f);

	daruma->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (brush->isHanded()) // 추후에 아이템 합치기 넣어서 잉크병이랑 붓 합칠 때 상호작용하게끔 바꾸자
		{
			daruma->setImage("Images/다루마_눈칠함.png");
			showMessage("스산한 느낌과 함께 철컥하는 소리가 들렸다.");
			// 스산한 배경음악 코드 추가
			// 추후 똑딱거리는 소리가 8번 나게끔 코드를 추가한다. 암호에 사용할 것.
			// 이후로부터 방 왼편의 색즉시공의 "공" 부분이 붉게 변한다. (암호)
		}
		else
		{
			showMessage("눈을 칠하고 소원을 빌면 이루어준다는 인형이다.\n 아직은 눈이 안 칠해져있다. \n 여기서 나가게 해줘.");
		}
		return true;
		});

	startGame(room1);


	return 0;
}

