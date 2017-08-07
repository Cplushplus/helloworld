#include <iostream>
#include <string>

class Model;
class View;
class Controller;



using std::string;
using std::cout;
using std::endl;

class Model {
	private:
		string mText;
	public:
		Model() {
			
		}
		
		Model(const string &text) {
			setText(text);
		}
		
		void setText(const string &text) {
			mText = text;
		}
		
		string getText() {
			return mText;
		}
};

class View {
	private:
		Model mModel;
	public:
		View() {
			
		}
		
		View(const Model &model) {
            mModel = model;
        }
        
		void setModel(Model &model) {
			mModel = model;
		}
		
		void display() {
			 cout << mModel.getText() << endl;
		}
};

class Controller {
	private:
		Model mModel;
		View mView;
	public:
		Controller(const Model &model, const View &view) {
          setModel(model);
          setView(view);        
        }
        
		void setModel(const Model &model) {
			mModel = model;
		}
		
		void setView(const View &view) {
			mView = view;
		}
		
		void onLoad() {
			mView.display();
		}
};




int main() {
	Model mModel("Helloworld 8");
	View mView(mModel);
	
	Controller mController(mModel, mView);
	
	mController.onLoad();
	
	return 0;
}
