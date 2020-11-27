// Copyright 2019 The MWC Developers
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef U_CHANGENODE_H
#define U_CHANGENODE_H

#include "../control_desktop/mwcdialog.h"
#include "../wallet/wallet.h"

namespace Ui {
class ChangeNode;
}

namespace bridge {
class Config;
}

namespace dlg {

class ChangeNode : public control::MwcDialog {
    Q_OBJECT
public:
    explicit ChangeNode( QWidget *parent, const wallet::MwcNodeConnection & _nodeConnection, const QString & network );
    ~ChangeNode();

    wallet::MwcNodeConnection getNodeConnectionConfig() const {return nodeConnection;}

private slots:

    void on_resetButton_clicked();
    void on_cancelButton_clicked();
    void on_applyButton_clicked();
    void on_radioCloudNode_clicked();
    void on_radioEmbeddedNode_clicked();
    void on_radioCustomNode_clicked();
    void on_selectNodeDataLocationBtn_clicked();
private:
    Ui::ChangeNode *ui;
    wallet::MwcNodeConnection nodeConnection;

    bridge::Config * config = nullptr;
};

}

#endif // U_CHANGENODE_H
