require "spec_helper"

describe URIParse do
  describe "#parse" do
    it "scheme" do
      res = URIParse.parse("http://foo.com")

      expect(res[:scheme]).to eq("http")
    end
  end
end

