Pod::Spec.new do |s|
s.name         = "GlobalPlayer"
s.version      = "0.0.1"
s.summary      = "Popup controller such as the one in Apple Music."
s.homepage     = "https://github.com/bandlab/LNPopupController"
s.license      = "MIT"
s.author       = { "LeoNatan" => "lnatan@wix.com" }
s.platform     = :ios, '9.0'
s.source       = { :git => "git@github.com:bandlab/LNPopupController.git", :tag => 'v2.1.4' }
s.source_files = 'Pod/LNPopupController/LNPopupController/*','Pod/LNPopupController/LNPopupController/Private/*'
s.requires_arc = true
end
