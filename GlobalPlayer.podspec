Pod::Spec.new do |s|
s.name         = "GlobalPlayer"
s.version      = "2.1.4.1"
s.summary      = "Popup controller such as the one in Apple Music."
s.homepage     = "https://github.com/bandlab/LNPopupController"
s.license      = "MIT"
s.author       = { "LeoNatan" => "lnatan@wix.com" }
s.platform     = :ios, '9.0'
s.source       = { :git => "https://github.com/bandlab/LNPopupController.git", :tag => 'v2.1.4.1' }
s.source_files = "Sources/**/*.{h,m}"
s.requires_arc = true
end
